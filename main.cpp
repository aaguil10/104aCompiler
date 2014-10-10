// $Id: main.cpp,v 1.1 2014-10-03 18:45:23-07 - - $
#include <iostream>
#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "stringset.h"
#include "auxlib.h"

int main (int argc, char **argv) {
   int c;
   bool lFlag = false;
   bool yFlag = false;
   string atOpt = "";
   string dOpt = "";
   string fileName = argv[argc - 1];
   //for (int i = 1; i < argc; ++i) {
   while ((c = getopt (argc, argv, "ly@:D:")) != -1){
      switch (c){
         case 'l':
            cout << "Set 'l' flag!" << endl;
            lFlag = true;
            continue;
         case 'y':
            cout << "Set 'y' flag!" << endl;
            yFlag = true;
            continue;
         case '@':
            cout << "Set @ flag!" << endl;
            //cout << "   " << optarg << endl;
            atOpt = optarg;
            continue;
         case 'D':
            cout << "Set '-D' flag!" << endl;
            //cout << "   " << optarg << endl;
            dOpt = optarg;
            continue;

      }
      //cout << "l: " << lFlag << " y: " << yFlag << endl;
      //cout << "d: " << dOpt << " @: " << atOpt << endl;

      //cout << argv[i] << endl;
      /*const string* str = intern_stringset (argv[i]);
      printf ("intern (\"%s\") returned %p->\"%s\"\n",
              argv[i], str->c_str(), str->c_str());*/
   }
   cout << "****" << fileName << "****" << endl;
   cout << "l: " << lFlag << " y: " << yFlag << endl;
   cout << "d: " << dOpt << " @: " << atOpt << endl;

   set_execname (argv[0]);

   dump_stringset (stdout);
   return EXIT_SUCCESS;
}


/*   set_execname (argv[0]);
   for (int argi = 1; argi < argc; ++argi) {
      char* filename = argv[argi];
      string command = CPP + " " + filename;
      printf ("command=\"%s\"\n", command.c_str());
      FILE* pipe = popen (command.c_str(), "r");
      if (pipe == NULL) {
         syserrprintf (command.c_str());
      }else {
         cpplines (pipe, filename);
         int pclose_rc = pclose (pipe);
         eprint_status (command.c_str(), pclose_rc);
      }
   }
   return get_exitstatus();
*/

