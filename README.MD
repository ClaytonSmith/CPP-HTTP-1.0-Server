### DataCom Assignment 1

This is a socketting exercise written for my Data Communications class. The goal of this assignment is to implement HTTP/1.0 GET and PUT requests using sockets.

## Installation and Dependencies

   This project is dependent on Poco, a C++ library. This project was developed in Linux so only linux installation instructions will be provided.

  
1. Download and extract Poco.
   The download link for Poco can be found [here](http://pocoproject.org/download/index.html).
   The Basic edition of Poco is sufficiant.
   Once downloaded, extract the file to a location of your choosing.
 
2. Install Poco
   The newly extracted directory will contain a script called  `config`. Run 
   > ./config

   Once the script has finished, the library must be built.
   > make -s

   This process will take some time.  
  

  After Poco has finished building, install it to `/usr/local` for the linker to find.
  > sudo make -s install

  Followed by
  > sudo ldconfig  

  Poco should now be installed
  
2. Clone the repo
   > git clone https://github.com/ClaytonSmith/CPP-HTTP-1.0-Server

3. Build
   > make

   If you are able to successfully build the server and client, then Poco was installed correctly.


## Running the Client and Server
   
   The build process will produce two executable, `server` and `client`.
   Run `./server` or `./client` to see what arguments each application expects.

   To run the server, run `./server 3000`.
   This will run the server on port 3000.
   When the server is running, open a web browser and navigate to `127.0.0.1:3000` (or the address of the machine).
   A simple HTML page should be displayed.
   If the page is visible, than the server is running properly. 

   ![Working demo](https://github.com/ClaytonSmith/CPP-HTTP-1.0-Server/blob/master/Screenshots/ServerRunning.png)

   The client requires four run-time arguments.
   The client require a host to connect to, port number, HTTP method (`GET`, `PUT`), and file to retrieve or transmit.
   If the server is running, try running
   > ./client http://127.0.0.1 3000 GET index.html

   This contents of `index.html` will be displayed on screen.

   The client is also capable of making PUT requests.
   When given the path of a local file, the client is able to upload any reasonably sized sized file to any host, provided the host is willing to accept the upload. 
 
### Application design

## Server

# Application structure

    The server works by using Poco's HTTP server application tool set and extending it to suit the needs of the project. 
    The server contains three main types of objects, a server, request handler, and a request handler factory.
    `MyServerApp` extends from [`ServerApplication`](http://pocoproject.org/docs/Poco.Util.ServerApplication.html), `MyRequestHandlerFactory` from [``](http://pocoproject.org/docs/Poco.Net.HTTPRequestHandlerFactory.html), and both `GET` and 'POST' handlers from [`HTTPRequestHandler`](http://pocoproject.org/docs/Poco.Net.HTTPRequestHandler.html).
    

# How it works

  When any connection made to the server, a page is generated as a response to that connection. 
  If a `GET` request is made asking for `index.html`, then the server will generate a page titled `index.html` and send it to the client.
  ![Sample](https://github.com/ClaytonSmith/CPP-HTTP-1.0-Server/blob/master/Screenshots/local-GET-request.png?raw=true)
  Note how the response read "Hello world! this file name is /index.html".
  
  Same same is true for a `PUT` request. 
  When a `PUT` request is made, a page reading "Hello friend ..." will be made instead.

# Does it work
  The server is able to differentiate between `GET` and `PUT` requests. 
  When a `GET` request is made for a particular page, the server will generate that page and return it to the client.
  When a `PUT` request is made, the server is able to identify the request and assign the response action to the `PutRequestHandler`.
  Unfortunately, the server is unable to download a file form the client. 
  
  When a `PUT` request is made, the server is able to generate a response for the request but is unable to establish a connection to download the file.
  I believe this is due to a misunderstanding of the library rather than a networking issue.
  The error is `I/O Error: Broken pipe`.
  
  	     
# Trade-offs 
  One of the trade-offs with this application is that Poco does not provide a clean pathing solution for request and route handling.
  It may be due to my inexperience with Poco but I was unable to devise or find a scalable method for handling requests that did not involve massive `if` or `switch` statements.
  I would prefer to see `req.on( <path x>, <do y>)` type solution.  


## Client

# Application structure
  The client is a very simple application.
  There are no additional classes declared within [`client.cpp`](https://github.com/ClaytonSmith/CPP-HTTP-1.0-Server/blob/master/client.cpp). 
  The client only looks to take in ether a `GET` or `PUT` directive. 									              

# How it works
  Within [`client.cpp`](https://github.com/ClaytonSmith/CPP-HTTP-1.0-Server/blob/master/client.cpp) there exists one `if else` statement. 
  If the request being made is a `GET` request, then the client will execute the `GET` procedure located in the fist half of the conditional.
  If the request is a `PUT` request, then the client will execute the `PUT` procedure in the second half of the conditional.

# Does it work
  Yes, the client is able to make both `GET` and `PUT` requests.
  [Here]() is an example of the client performing a `GET` from CNN.com.
  Due to the servers inability to receive the `PUT` file request, I am unsure whether or not the client is able to make the request.
  
  When I attempted a `PUT` on sites like cnn.com, I received an error stating that the request being made is not accepted by the server.
  I assume that this is cnn.com disallowing `PUT` requests on their site rather then an improperly formed request on the client.
     
# Trade-offs 
  There are no major trade-offs for this application.
