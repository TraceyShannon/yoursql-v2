#include <iostream>
#include <stdlib.h>

using namespace std;

const int arr_len = 10;

void init_interface();
void init_spacing_arr();
int str_length(string str);
int arr_length(string str[]);
string to_lower_case(string str);
int find_max_str_length(int num[]);
void create_database(string input);
string check_user_input(string user_input);
void show_databases(string str[], int num[]);

int dt = 1;
int max_chars = 0;
int str_len_arr[arr_len];
int num_of_spaces[arr_len];

string main_str_arr[arr_len] = {
  "Database"
};

// ==== Beginning Of Main ==== //
int main(int argc, char const *argv[]) {



  init_spacing_arr();

  cout << "Welcome To Yoursql Monitor! A Cheap Knockoff of the Mysql database!" << "\n\n";
  cout << "Commands end with ; or \\g" << "\n\n";
  cout << "Please type 'quit' or 'exit' followed by the enter key to terminate the program." << endl;
  cout << "Just Don't Hit Control D or else you'll get an infinite loop!" << "\n\n";

  init_interface();

  return 0;
}
// ==== End OF Main ==== //

int str_length(string str) {

  int i = 0;

  while (str[i] != '\0') {
    i++;
  }

  return i;
}

int find_max_str_length(int num[]) {
  int max = 0;
  int i = 0;
  int save = 0;

  for (i = 0; i < arr_len; i++) {
    if (num[i] > max) {
      max = num[i];
      save = i;
    }
  }

  return save;
}

int arr_length(string str[]) {

  int i = 0;

  while (str[i] != "") {
    cout << str[i] << endl;
    i++;
  }

  return i;
}

void show_databases(string str[], int num[]) {
  cout << endl;
  cout << "+";
  for (int z = 0; z < str_length(str[max_chars]) + 2; z++) {
    cout << "-";
  }
  cout << "+" << endl;
  for (int i = 0; i < 1; i++) {
    cout << "| " << str[i];
    for (int x = 0; x < num[i]; x++) {
      cout << " ";
    }
    cout << "|";
  }

  cout << endl;
  // ====  Elements Below The Title ==== //
  cout << "+";
  for (int z = 0; z < str_length(str[max_chars]) + 2; z++) {
    cout << "-";
  }
  cout << "+" << endl;
  for (int i = 1; i < dt; i++) {
    cout << "| " << str[i];
    for (int x = 0; x < num[i]; x++) {
      cout << " ";
    }
    cout << "|" << endl;
  }
  cout << "+";
  for (int z = 0; z < str_length(str[max_chars]) + 2; z++) {
    cout << "-";
  }
  cout << "+" << endl;
  cout << dt - 1 << " rows in set (how long did this take?)" << "\n\n";

  //
}

string to_lower_case(string str) {
  string new_str;
  int i = 0;

  while (str[i] != '\0') {
    if (str[i] != ';' && (str[i] != '\\' && str[i + 1] != 'g')) {
      new_str += tolower(str[i]);
    }
    i++;
  }

  return new_str;
}

void init_spacing_arr() {

  for (int i = 0; i < arr_len; i++) {
    str_len_arr[i] = str_length(main_str_arr[i]);
  }

  max_chars = find_max_str_length(str_len_arr);

  for (int i = 0; i < arr_len; i++) {
    num_of_spaces[i] = (str_length(main_str_arr[max_chars]) - str_len_arr[i]) + 1;
  }

  //
}

string check_user_input(string user_input) {

  string ender = "";

  if (str_length(user_input) == 0) {
    return "empty";
  }

  if (user_input[str_length(user_input) - 1] != ';' &&
   (user_input[str_length(user_input) - 2] != '\\' && user_input[str_length(user_input) - 1] != 'g')) {
    while (ender != ";" || ender != "\\g") {
      cout << "       -> ";
      getline(cin, ender);
      user_input += ender;
      if (ender[str_length(ender) - 1] == ';' ||
      (ender[str_length(ender) - 2] == '\\' && ender[str_length(ender) - 1] == 'g')) {
        break;
      } else {
        continue;
      }
    }
  }
  string new_str = "";
  user_input = to_lower_case(user_input);
  if (user_input[str_length(user_input) - 1] == 'g') {
    for (int i = 0; i < str_length(user_input) - 1; i++) {
      new_str += user_input[i];
    }
    user_input = new_str;
  }

  return user_input;
}

void create_database(string input) {

  main_str_arr[dt] = input;

  dt++;


}

// ==== Nothing Should Go Beneath This Line ==== //

void init_interface() {

  string user_input = "";

  while (user_input != "quit" || user_input != "exit") {
    init_spacing_arr();
    cout << "yoursql>> ";
    getline(cin, user_input);
    user_input = check_user_input(user_input);

    if (user_input == "empty") {
      continue;
    }

    if (user_input == "quit" || user_input == "exit") {
      cout << "Bye!" << endl;
      return;
    }

    if (user_input == "show databases") {
      show_databases(main_str_arr, num_of_spaces);
    } else if (user_input == "clear") {
      system("clear");
      continue;
    } else if (user_input == "create database") {
      string input = "";
      cout << "Enter Databse Name: ";
      cin >> input;
      input = check_user_input(input);
      create_database(input);
      cout << "Database " << input << " Has Been Created, Press Enter" << "\n\n\n";
    }
     else {
      cout << "** I see you included an ending statement, so maybe something is misspelled. **" << endl;
      cout << "You might have a syntax error, but I'm honestly not sure. Sorry Dude..." << '\n';
      user_input = "";
      continue;
    }
  }

  //
}
