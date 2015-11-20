#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <iostream>
#include <string>
#include <fstream> 

using namespace Poco::Net;
using namespace Poco;
using namespace std;

bool is_numeric( char *number_string){
  string temp_number_string(number_string);
  return (temp_number_string.find_first_not_of( "0123456789" ) == string::npos);
}


int main(int argc, char *argv[]){

  // Check that all four arguments are being passed
  if (argc < 4) {
    cout << "Usage: http://<host> <port> <method> <target_file>>" << endl;
    exit(-1);

    // Check that the port is a numeric value
  } else if( !is_numeric( argv[2] )){ // Check that only strings containing numbers were passed
    cout << '"' << argv[2] << "\" is not a valid port number." << endl << endl;
    exit(-1);
  }
  
  // Check if user is asking to make a GET request 
  if( HTTPRequest::HTTP_GET.compare( argv[3] )){
    
    try {

      // Create URI cocket object with hostname and client session with port number
      URI uri(argv[1]);
      HTTPClientSession session(uri.getHost(), atoi( argv[2] ));
    
      
      // File path
      string path(argv[3]);
        
      // send request
      HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_0);
      session.sendRequest(req);
      
      // get response
      HTTPResponse res;
      cout << res.getStatus() << " " << res.getReason() << endl;
      
      // print response
      istream &is = session.receiveResponse(res);
      StreamCopier::copyStream(is, cout);
    }

    catch (Exception &ex) {
      cerr << ex.displayText() << endl;
      return -1;
    }

    // PUT request 
  } else if( HTTPRequest::HTTP_PUT.compare( argv[3] )){
    try {
      
      // Pass client session host and filename 
      HTTPClientSession session( argv[1] );
      HTTPRequest request(HTTPRequest::HTTP_PUT, argv[4]);

      // send first request
      std::ostream& os = session.sendRequest(request);
      
      // select file to stream
      std::ifstream ifs( argv[4] ); // missing: error handling
      Poco::StreamCopier::copyStream(ifs, os);

      // Final transaction between host and client
      Poco::Net::HTTPResponse response;
      std::istream& rs = session.receiveResponse(response);
      
      // Error checking
    } catch (Poco::Exception& e) {
      std::cout << e.displayText() << std::endl;
    }
  } else {
    cout << "The method \"" << argv[3] << "\" is not supported yet." << endl;
    cout << "Only \"GET\" and \"PUT\" are supported" << endl;
    exit( -1 );
  }
  
  return 0;
}
