## Installation and Dependencies

   This project is dependent on Poco, a C++ library. This project was developed in Linux so only linux installation instructions will be provided.

  
1. Download Poco
   The download link for Poco can be found (here)[http://pocoproject.org/download/index.html]. Download the Basic edition of Poco.
 
2. Install Poco
   The newly extracted directory will contain a script called  `config`. Run 
   > ./config

   Once the script has finished running, the library must be built. To do this, run
   > make -s

   This process will take some time.  
  

  After Poco has finished building, install it to `/usr/local` for g++ to find.
  > sudo make -s install

  Followed by
  > sudo ldconfig  

  Poco should now be installed
  
2. Clone the REPO_NAEM repo
   > git clone REPO_NAME

3. Build
   > make

## Running the Client and Server
   
   The build precess will produce two excecutables, `server` and `client`. Run `./server` or `./client` to see what arguments are accepted by each application. 

   To run the server, run `./server 3000`. This will run the server on port 3000. When the server is running, open a web browser and navigate to  `127.0.0.1:3000` (or the address of the machine). A simple HTML page should be displayed. If the page is visable, than the server is running propperly. 

   The client requires four runtime arguments as opposed to the servers one. The client require a host to connect to, port number, HTTP method (`GET`, `PUT`), and file to retrieve or transmit. If the server is running, try running
   > ./client http://127.0.0.1 3000 GET index.html

   This contents of `indedx.html` will be displayed on screen.
