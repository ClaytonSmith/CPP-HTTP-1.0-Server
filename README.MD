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
   
