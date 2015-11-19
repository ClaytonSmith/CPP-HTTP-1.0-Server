#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace Poco::Net;
using namespace Poco::Util;
using namespace std;



bool is_numeric( char *number_string){
  string temp_number_string(number_string);
  return (temp_number_string.find_first_not_of( "0123456789" ) == string::npos);
}

class MyRequestHandler : public HTTPRequestHandler {
public:
  virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp){
    resp.setStatus(HTTPResponse::HTTP_OK);
    resp.setContentType("text/html");
    
    ostream& out = resp.send();
    out << "<h1>Hello world!</h1>"
        << "<p>Count: "  << ++count         << "</p>"
        << "<p>Host: "   << req.getHost()   << "</p>"
        << "<p>Method: " << req.getMethod() << "</p>"
        << "<p>URI: "    << req.getURI()    << "</p>";
    out.flush();
    
    cout << endl
         << "Response sent for count=" << count
         << " and URI=" << req.getURI() << endl;
  }
  
private:
  static int count;
};

int MyRequestHandler::count = 0;

class MyRequestHandlerFactory : public HTTPRequestHandlerFactory 
{
public:
  virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &)
  {
    return new MyRequestHandler;
  }
};

class MyServerApp : public ServerApplication 
{
protected:
  int main(const vector<string> &args){
    
    HTTPServer s(new MyRequestHandlerFactory, ServerSocket( atoi( args[1].c_str() ) ), new HTTPServerParams);
    
    s.start();
    cout << endl << "Server started" << endl;
    cout << "Listening on port: " << args[1] << endl ; 
    
    waitForTerminationRequest();  
    
    cout << endl << "Shutting down server..." << endl;
    s.stop();
    
    return Application::EXIT_OK;
  }
};


void usage(){
  perror("Usage: ./server <PORT_NUMBER>");
  perror("Please provide a port in range of 1024 - 49151 for the server to run on. Recommended: 300");
  exit(-1);
}

int main(int argc, char* argv[]){
  
  
  if( argc <= 1 ) {  // Check that at least one argument was given. 
    cout << "Missing arguments" << endl << endl; 
    usage();
    
  } else if( !is_numeric( argv[1] )){ // Check that only strings containing numbers were passed
    cout << '"' << argv[1] << "\" is not a valid port number." << endl << endl;
    usage();
    
  } else if( not (1023 < atoi( argv[1] ) and atoi( argv[1] ) < 49152) ){ // Check that port was in specified range
    cout << argv[1] << " is out of the specified range. Please enter a valid port number." << endl << endl;
    usage();
    
  } else {
    // Nothing to do here, all good 
  }
  
  
  MyServerApp app;
  return app.run(argc, argv);
}

