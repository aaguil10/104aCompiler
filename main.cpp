// $Id: main.cpp,v 1.1 2014-10-03 18:45:23-07 - - $
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "stringset.h"
#include "auxlib.h"
#include "cppstrtok.h"
 
bool debug = false;
void  db(string m){ if(debug){ cerr << m << endl;} };
const string CPP = "/usr/bin/cpp";

int main (int argc, char **argv) {
   int c;
   bool lFlag = false;
   bool yFlag = false;
   string atOpt = "";
   string dOpt = "";
   char* fileName = argv[argc - 1];
   //for (int i = 1; i < argc; ++i) {
   while ((c = getopt (argc, argv, "ly@:D:")) != -1){
      switch (c){
         case 'l':
            db( "Set 'l' flag!");
            lFlag = true;
            continue;
         case 'y':
            db("Set 'y' flag!");
            yFlag = true;
            continue;
         case '@':
            db("Set @ flag!");
            //cout << "   " << optarg << endl;
            set_debugflags (optarg);
            atOpt = optarg;
            debug = true;
            continue;
         case 'D':
            db("Set '-D' flag!");
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
   string m = "l: " + lFlag;
   string n = " y: " + yFlag;
   db(m + n);
   db("d: " + dOpt + " @: " + atOpt);

   set_execname (argv[0]);
   string command = CPP + " " + fileName;
   //printf ("command=\"%s\"\n", command.c_str());
      FILE* pipe = popen (command.c_str(), "r");
      if (pipe == NULL) {
         syserrprintf (command.c_str());
      }else {
         cpplines (pipe, fileName);
         int pclose_rc = pclose (pipe);
         eprint_status (command.c_str(), pclose_rc);
      }

   int len = strlen(fileName);
   fileName[len-2] = 's';
   fileName[len-1] = 't';
   fileName[len] = 'r';
   fileName[len+1] = '\0';
   //ofstream outputFile(fileName);
   FILE* str_name = fopen(fileName, "w+");

   dump_stringset (str_name);
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

