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
            set_debugflags (optarg);
            atOpt = optarg;
            debug = true;
            continue;
         case 'D':
            db("Set '-D' flag!");
            dOpt = optarg;
            continue;
      }
   }
   string m = "l: " + lFlag;
   string n = " y: " + yFlag;
   db(m + n);
   db("d: " + dOpt + " @: " + atOpt);

   set_execname (argv[0]);
   string command = CPP + " " + fileName;
   FILE* pipe = popen (command.c_str(), "r");
   if (pipe == NULL) {
      syserrprintf (command.c_str());
   }else {
      cpplines (pipe, fileName);
      int pclose_rc = pclose (pipe);
      eprint_status (command.c_str(), pclose_rc);
   }

   int len = strlen(fileName);
   char* file_str = (char*)malloc(len + 2); 
   strcpy(file_str, fileName);
   file_str[len-2] = 's';
   file_str[len-1] = 't';
   file_str[len] = 'r';
   file_str[len+1] = '\0';
   FILE* str_name = fopen(file_str, "w+");

   dump_stringset (str_name);
   free(file_str);
   return EXIT_SUCCESS;
}


