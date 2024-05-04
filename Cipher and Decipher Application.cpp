/*
FCAI Cairo University Cipher and Decipher Application
Purpose: Application that encrypts and decrypts messages using different cipher techniques
Under supervision by Dr.Mohamed El-Ramly
Authors:
1. Youssef Amgad Abd Al Halim Ahmed solved simple substitution,route cipher,rail fence cipher,atbash cipher,menu

2. Amr Khaled Ahmed Abd Al Hamid Mohamed solved XOR cipher,Vignere cipher,polybius cipher

3. Mohamed Ahmed Mohamed Abd Al Wahab solved Affine cipher, Morse cipher,baconian cipher

*/
# include <iostream>
# include <cctype>
# include <string>
#include<cctype>
# include <cstring>
# include <algorithm>
# include <vector>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <regex>
using namespace std;
int simple_substitution(string msg);
string substitution_checker(string msg);
int Rail_fence(string msg);
bool is_correct_10(string cipher);
bool is_correct_ab(string cipher);
string display(string msg);
int baconian_main();
string menu_baconian();
string characters(const string &input);
string inp();
string inp_2();
string inp_3();
string ciphered_1(string decipher);
string ciphered_2(string decipher);
string deciphered_1(string cipher);
string deciphered_2(string cipher);
int menu_cipher();
int menu_decipher();
string menu();
int Atbash(string msg);
int polybius_menu();
void cipher();
void decipher();
void frame_print();
bool isExist_key(int temp);
bool isDigits(string statement);
int check_for_string();
string encryption(string temp);
string decryption(string before);
string ignore_statement(string before);
string ignore_statement_XOR(string before);
bool availability (string temp);
bool checker_string(string msg);
bool is_alpha(string msg);
int Route_Cipher(string msg);
bool key_check(string key);
string ignore_statement_route(string before);
void route_main();
bool check_for_characters(const string& str);
bool check_for_hexadecimal(const string& statement);
void main_vigenere();
void vigenere_decipher(const string& message, const string& keyword);
void vigenere_cipher(const string& statement, const string& keyword);
void XOR_cipher();
void main_affine();
string valid_characters();
string affine_menu();
string affine_cipher(string s);
string affine_decipher(string s);
bool validate_characters(string input);
string morse_input_cipher();
string morse_input_decipher();
string morse_cipher(string cipher);
string morse_decipher(string cipher);
string morse_menu();
void morse_main();
int key[5];
vector<vector <string>> frame = {{"A","B","C","D","E"},{"F","G","H","IJ","K"},{"L","M","N","O","P"},{"Q","R","S","T","U"},{"V","W","X","Y","Z"}};

int main() {
    // welcomes user to program
    cout << "Welcome to our encryption and decryption application" << endl;
    string msg;


    // displays cipher menu for user
    string choice = menu();
    // according to user choice go to chosen cipher
    if (choice == "K") {
        cout << "Thank you for using our cipher application" << endl;
        exit(0);
    } else if (choice == "C") {
        polybius_menu();
    } else if (choice == "B") {
        baconian_main();
    }
    else if(choice=="F"){
        route_main();
    }
    else if(choice=="D"){
        cout<<"Please enter your message: "<<endl;
        cin.ignore();
        getline(cin,msg);
        msg= substitution_checker(msg);
        simple_substitution(msg);
    }
    else if(choice=="G"){
        main_vigenere();
    }
    else if(choice=="H"){
        XOR_cipher();
    }
    else if(choice=="I"){
        main_affine();
    }
    else if(choice=="J"){
        morse_main();
    }

    // different condition for message other than the previous ciphers
    msg = display(msg);
    if (choice == "A")Atbash(msg);

    else if(choice=="E")Rail_fence(msg);
}
string display(string msg){
    //  takes message user wants to encrypt or decrypt and validates it
    cout<<"Please enter your message: "<<endl;
    cin.ignore();
    getline(cin,msg);
    msg= ignore_statement(msg);
    while(msg.empty()){
        cout<<"Please enter a valid message: "<<endl;
        getline(cin,msg);
        msg= ignore_statement(msg);

    }

    while(msg.empty() || !checker_string(msg)){
        cout<<"Please enter a valid message: "<<endl;
        getline(cin,msg);
        msg= ignore_statement(msg);
    }
    cout<<endl;
    return msg;
}
string menu(){
    // function that displays all encryption styles for user to choose from
    string choice;
    string msg;

    cout<<"Here are the cipher styles"<<endl;
    cout<<"A. Atbash Cipher"<<endl;
    cout<<"B. Baconian Cipher"<<endl;
    cout<<"C. Polybius Square Cipher"<<endl;
    cout<<"D. Simple Substitution Cipher"<<endl;
    cout<<"E. Rail Fence Cipher"<<endl;
    cout<<"F. Route Cipher"<<endl;
    cout<<"G. Vignere Cipher"<<endl;
    cout<<"H. XOR Cipher"<<endl;
    cout<<"I. Affine Cipher"<<endl;
    cout<<"J. Morse Cipher"<<endl;
    cout<<"K. exit"<<endl;
    cout<<"Please choose according to corresponding alphabet: "<<endl;
    cin>>choice;

    // making sure of validity of choice
    while(true) {
        if(choice=="A") return choice;
        else if(choice=="B")return choice;
        else if(choice=="C")return choice;
        else if(choice=="D")return choice;
        else if(choice=="E")return choice;
        else if(choice=="F")return choice;
        else if(choice=="G")return choice;
        else if(choice=="H")return choice;
        else if(choice=="I")return choice;
        else if(choice=="J")return choice;
        else if(choice=="K")return choice;
        else{
            cout<<"Please enter a valid choice: "<<endl;
            cin>>choice;
        }

    }

}
int Atbash(string msg){
    // display menu of encryption and decryption
    string choice;
    cout<<"Welcome, what would you like to do today?"<<endl;
    cout<<"1. Cipher a message"<<endl;
    cout<<"2. Decipher a message"<<endl;
    cout<<"3. exit"<<endl;
    cout<<"Please enter 1 or 2 or 3: "<<endl;
    cin>>choice;

    // making sure of validity of choice
    while(true) {
        if(choice=="1")break;
        else if(choice=="2")break;
        else if(choice=="3"){
            cout<<"Thank you for using this program"<<endl;
            exit(0);
        }
        else{
            cout<<"Please enter a valid choice: "<<endl;
            cin>>choice;
        }
    }

    // Menu to choose from type of Atbash cipher
    cout<<"Choose between two versions of Atbash cipher"<<endl;
    cout<<"1. full alphabet"<<endl;
    cout<<"2. Half the alphabet"<<endl;
    cout<<"Please enter 1 or 2: "<<endl;
    string choice2;
    cin>>choice2;

    // validating choice2
    while(true) {
        if(choice2=="1")break;
        else if(choice2=="2")break;
        else{
            cout<<"Please enter a valid choice: "<<endl;
            cin>>choice2;
        }
    }
    // full alphabet
    if(choice2=="1") {
        // setting up string and loop to apply atbash encryption
        // leaving spaces, numbers and punctuation as it is
        // looping on each index of msg and changing index according to the letter position in cipher or cipher2 string
        string cipher = "abcdefghijklmnopqrstuvwxyz";

        // getting rid of the spaces, numbers and punctuation marks
        string final_msg = "";
        for (int i = 0; i < msg.length(); i++) {
            if (isalpha(msg[i])) {
                msg[i] = toupper(msg[i]);
                final_msg += msg[i];
            }
        }
        // ciphering message according to full alphabet atbash
        for (int i = 0; i < final_msg.length(); i++) {
            final_msg[i] = tolower(final_msg[i]);
            for (int j = 0; j < cipher.length(); j++) {
                if (final_msg[i] == cipher[j]) {
                    final_msg[i] = cipher[25 - j];
                    final_msg[i] = toupper(final_msg[i]);
                    break;
                }

            }
        }

        // printing new msg
        if(choice=="1"){
            cout<<"Your encrypted message is: "<<endl;
            cout<<final_msg;
        }
        else if(choice=="2"){
            cout<<"Your decrypted message is: "<<endl;
            cout<<final_msg;
        }
    }

    // Half alphabet
    if(choice2=="2"){
        // setting up string and loop to apply atbash encryption
        // leaving spaces, numbers and punctuation as it is
        // looping on each index of msg and changing index according to the letter position in cipher or cipher2 string
        string cipher="abcdefghijklm";
        string cipher2="nopqrstuvwxyz";

        // getting rid of the spaces, numbers and punctuation marks
        string final_msg="";
        for(int i=0; i<msg.length(); i++){
            if(isalpha(msg[i])){
                msg[i]= toupper(msg[i]);
                final_msg+=msg[i];
            }
        }

        // ciphering final msg according to cipher and cipher2
        for(int i=0; i<final_msg.length(); i++){
            final_msg[i]=tolower(final_msg[i]);
            for(int j=0; j<cipher.length(); j++){
                if(final_msg[i]==cipher[j]){
                    final_msg[i]=cipher[12-j];
                    final_msg[i]=toupper(final_msg[i]);
                    break;
                }
                else if(final_msg[i]==cipher2[j]){
                    final_msg[i]=cipher2[12-j];
                    final_msg[i]=toupper(final_msg[i]);
                    break;
                }
            }
        }

        // printing new msg
        if(choice=="1"){
            cout<<"Your encrypted message is: "<<endl;
            cout<<final_msg;
        }
        else if(choice=="2"){
            cout<<"Your decrypted message is: "<<endl;
            cout<<final_msg;
        }
    }
    cout<<endl<<endl;
    string choice_ctn;
    cout<<"If you would like to continue, enter A"<<endl;
    cout<<"If you don't want to continue, enter B"<<endl;
    cin >> choice_ctn;
    while (true) {
        if (choice_ctn == "A") main();
        else if (choice_ctn == "B"){
            cout<<"Thank you for using this program"<<endl;
            exit(0);
        }
        else {
            cout << "Please enter a valid choice: " << endl;
            cin >> choice_ctn;
        }
    }


}

int polybius_menu(){
    cout << "***** Welcome to polybius-cipher application *****" << endl;
    string choice;
    cout << "please select\n1 if you want to encrypt\n2 if you want decrypt\n3 if you want to exit" << endl;
    // get the choice for play
    cin >> choice;
    if (choice == "1"){
        cipher();
    }else if (choice == "2"){
        decipher();
    }else if (choice == "3") {
        cout<<"Thank you for using this program"<<endl;
        exit(0);
    }
    // if the choice was wrong ask the user for it again
    while (choice != "1" && choice != "2" && choice !="3"){
        cout << "Invalid input. please select\n1 if you want to encrypt\n2 if you want 2 decrypt\n3 if you want to exit" << endl;
        cin >> choice;
        if (choice == "1"){
            cipher();
        }else if (choice == "2"){
            decipher();
        }else if (choice == "3"){
            cout<<"Thank you for using this program"<<endl;
            exit(0);
        }
    }
}

void cipher(){
    string statement, encrypt_word, temp_frame, statement_copy;

    int temp;
    bool isExist = false;
    // get the statement
    cout << "enter the statement:\n";
    getline(cin, statement);
    getline(cin, statement);
    // ignore anything otherwise the alphabetic characters
    statement = ignore_statement(statement);

    //then I will check id the code is empty
    while (statement.empty()){
        cout << "Invalid input\nPlease write a valid statement with including characters\n";
        getline(cin,statement);
        statement = ignore_statement(statement);

    }
    // make the statement and its copy to upper
    for (int i = 0; i < statement.size() ; i++ ){
        statement[i] = toupper(statement[i]);

    }
    statement_copy = statement;


    // enter the cipher key
    cout << "Enter the cipher key\n";

    for (int i = 0 ; i < 5 ; i++ ){
        do{
            cout << "Enter the index ("<< i+1 << ")" << endl;
            key[i] = check_for_string();
            temp = key[i];
            isExist = isExist_key(temp);
            // if the key element was not right ask for it again
            if (isExist || key[i] < 1 || key[i] > 5){cout << "Invalid input. ";}
        }while (isExist || key[i] < 1 || key[i] > 5);
    }




    frame_print();
    // encrypt the statement
    encrypt_word = encryption(statement);

    cout << "The encryption of " << statement_copy << " is: "<< encrypt_word <<endl;
    // reset the key for reuse
    for (int i = 0; i < 5 ;i++){
        key[i] = 10;
    }

    // ask the user if he wants to play again
    string choice1;
    do {
        cout << "Do you want to continue\npress 1 if yes\npress 2 if no\n";
        cin >> choice1;
        if (choice1 == "1"){
            main();
        }else if(choice1 == "2"){
            cout<<"Thank you for using this program"<<endl;
            exit(0);
        }else {
            cout << "Invalid input.";
        }
        // ask for the choice again if the user input wrong answer
    }while(choice1 != "1" && choice1 != "2");

}


void decipher(){
    string statement_copy, statement, decrypt_word, temp_frame;
    int temp;
    bool available,isExist = false, isDigit;
    //get the encrypt statement
    cout << "Please enter the encrypted code\n";
    // there is two getline because the first one destroyed by cin
    getline(cin, statement_copy);
    getline(cin, statement_copy);
    // ignore any spaces
    for (char i : statement_copy){
        if (!isspace(i)){
            statement += i;
        }
    }
    // this boolean value will check by functions if the encrypted code is correct

    isDigit = isDigits(statement);
    available = availability(statement);

    while ((!isDigit) || (statement.size()%2 != 0)|| (!available) || (statement.empty())){
        statement.clear();
        cout << "Invalid input .Please enter the encrypted code with numbers only such that the count of the numbers is even\nthe numbers should be between 1 and 5\n";
        getline(cin, statement_copy);
        // ignore any spaces
        for (char i : statement_copy){
            if (!isspace(i)){
                statement += i;
            }
        }
        // this boolean value will check by functions if the encrypted code is correct
        isDigit = isDigits(statement);
        available = availability(statement);
    }

    // enter the cipher key
    cout << "Enter the key\n";
    for (int i = 0 ; i < 5 ; i++ ){
        do{
            cout << "Enter the index ("<< i+1 << ")" << endl;
            key[i] = check_for_string();
            temp = key[i];
            isExist = isExist_key(temp);
            if (isExist || key[i] < 1 || key[i] > 5){cout << "Invalid input. ";}
        }while (isExist || key[i] < 1 || key[i] > 5);
    }


    frame_print();
    decrypt_word = decryption(statement);
    cout << "the word is " << decrypt_word << endl;
    // reset the key for reuse
    for (int i = 0; i < 5 ;i++){
        key[i] = 11;
    }
    string choice1;
    // ask the user if he wants to play again
    do {
        cout << "Do you want to continue\npress 1 if yes\npress 2 if no\n";
        cin >> choice1;
        if (choice1 == "1"){
            main();
        }else if(choice1 == "2"){
            cout<<"Thank you for using this program"<<endl;
            exit(0);
        }else {
            cout << "Invalid input.";
        }
        // ask for the choice again if the user input wrong answer

    }while(choice1 != "1" && choice1 != "2");
}


//// out function // done
string encryption(string temp){
    string res_1;
    string x, row , col;
    // set instead each character his row and column
    for (char ch : temp){
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0 ; k < frame[i][j].size() ; k++){
                    if (frame[i][j][k] == ch) {
                        // cat the row and the col in string
                        row = to_string(key[j]);
                        col = to_string(key[i]);
                        res_1 += col + row;
                    }
                }
            }
        }
    }
    return res_1;
}
string decryption(string before) {
    string after;
    int row, col;
    // this loop to get the right col and the right row
    for (int i = 0; i < before.size(); i += 2) {
        // cast the row character into integer then get his index
        int int_char = before[i] - '0';
        for (int j = 0; j < before.size() + 1; j++) {
            if (key[j] == int_char) {
                row = j;
                break;
            }
        }
        // cast the col character into integer then get his index
        int_char = before[i + 1] - '0';
        for (int j = 0; j < before.size();j++ ) {
            if (key[j] == int_char) {
                col = j;
                break;
            }
        }
        // add it to the return value
        after += frame[row][col];
    }
    return after;
}
void frame_print(){
    // print the game frame
    cout << "  ";
    // print the VL key
    for (int i = 0; i < 5 ; i++){
        cout << " " << key[i] ;
    }
    cout << endl;
    // print the frame
    for (int i = 0 ; i < 5 ; i++){
        // print the HR key
        cout << key[i] << "|";
        for (int j = 0 ; j < 5 ; j++){
            cout << " " << frame[i][j];
        }
        cout << endl;
    }

}
bool isExist_key(int temp){
    // to check if the key is duplicate
    for (int i = 0 ; i < 5 ; i++){
        if (temp == key[i]){
            for (int j = i+1 ; j < 5 ; j++){
                if (temp == key[j]){
                    cout << "Please enter a different number\n";
                    return true;
                }
            }
        }
    }
    return false;
}
bool isDigits(string statement){
    for (char i : statement){
        if (!isdigit(i)){
            return false;
        }
    }
    return true;
}
int check_for_string() {
    //to validate for the row and column is string or no
    string x;
    cin >> x;
    while (true) {
        bool is_digit = true;
        for (char i : x) {
            if (isdigit(i) == 0) {
                is_digit = false;
                break;
            }
        }
        if (is_digit) {
            int y = stoi(x);

            return y;
        }
        else {
            cout << "Please enter an integer: " << endl;
            cin >> x;
        }
    }
}
string ignore_statement(string before){
//    to ignore anything otherwise alphabetic and return only alphabetic characters
    string after;
    for (int i = 0; i < before.size(); ++i) {
        if (isalpha(before[i])){
            after += before[i];
        }
    }
    return after;
}


string ignore_statement_XOR(string before){
//    to ignore anything otherwise alphabetic and digits then return only alphabetic characters and digits
    string after;
    for (int i = 0; i < before.size(); ++i) {
        if (isalpha(before[i]) || isspace(before[i]) || isdigit(before[i]) || ispunct(before[i])){
            after += before[i];
        }
    }
    return after;
}


bool availability (string temp){
    int i_ch;
    for (char ch : temp){
        i_ch = ch - '0';
        if (i_ch < 1 || i_ch > 5){
            return false;
        }
    }
    return true;
}
bool checker_string(string msg){
    for(int i=0; i<msg.length(); i++){
        if(isspace(msg[i])){
            continue;
        }
        else if(!isalpha(msg[i])){
            return false;
        }
    }
    return true;
}

int baconian_main(){
    string temp = menu_baconian();
    if (temp == "A") {
        string strPair = inp();
        int men = menu_cipher();
        if (men == 1) {
            cout << "ciphered string as characters: " << ciphered_1(strPair) << endl;
        }
        else if (men == 2) {
            cout << "ciphered string as binary digits: " << ciphered_2(strPair) << endl;
        }
        else if (men == 3) {
            cout << "ciphered string as characters: " << ciphered_1(strPair) << endl;
            cout << "ciphered string as binary digits: " << ciphered_2(strPair) << endl;
        }
    }
    else if (temp == "B") {
        int men = menu_decipher();
        if (men == 1){
            string strPair = inp_2();
            cout<<"deciphered string is : "<<deciphered_1(strPair);
        }
        else if(men == 2){
            string decipherd = inp_3();
            cout<<"deciphered string is : "<<deciphered_2(decipherd);
        }
    }
    else if(temp == "C"){
        cout<<"Thank you for using this program\n";
        exit(0);
    }
    string choice_ctn;
    cout<<endl<<endl;
    cout<<"If you would like to continue, enter A"<<endl;
    cout<<"If you don't want to continue, enter B"<<endl;
    cin >> choice_ctn;
    while (true) {
        if (choice_ctn == "A") main();
        else if (choice_ctn == "B"){
            cout<<"Thank you for using this program"<<endl;;
            exit(0);

        }
        else {
            cout << "Please enter a valid choice: " << endl;
            cin >> choice_ctn;
        }
    }


}

string characters(const string &input) {
    string alphapitics;
    long long counter=0;
    for (char chr : input) { // iterate on indexes of input
        if (toupper(chr)>='A'&&toupper(chr)<='Z') { //check if uppercase of chr is between A and Z or not
            alphapitics += chr;
            counter++;
        }
    }
    if(counter==0){
        cout<<"Please enter a message with alphabetic characters: "<<endl;
        getline(cin,alphapitics);
        alphapitics= characters(alphapitics);
    }
    return alphapitics; // return value of alphapitics to use it in another place on program
}

string menu_baconian() {
    cout << "A: Cipher string" << endl << "B: Decipher string" << endl<<"C: exit"<<endl;
    cout<<"Please enter A or B or C"<<endl;
    string choice;
    cin.ignore(256,'\n');
    cin>>choice; // make user input his choice
    for (int i = 0; i < choice.size(); i++) { // iterate on indexes of choice
        choice[i] = toupper(choice[i]); // make choice on index i is uppercase character
    }

    while (choice != "A" && choice != "B"&& choice!="C") { // iterate when choice is not equal to A and B and C
        cout << "Invalid choice" << endl;
        cout << "A: Cipher string" << endl << "B: Decipher string" << endl<< "C: exit"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>choice;
        for (int i = 0; i < choice.size(); i++) { // iterate on indexes of choice
            choice[i] = toupper(choice[i]); // make choice on index i is uppercase character
        }

    }

    return choice; // return value of choice to use it again
}

int menu_cipher(){
    cout<<"Do you want to cipher string as characters or binary digits"<<endl;
    cout<<"1:cipher to characters"<<endl;
    cout<<"2:cipher to binary digits"<<endl;
    cout<<"3:both"<<endl;
    int men;
    cout<<"choose between 1&2&3: "<<endl;
    cin>>men;
    while(men!=1 && men!=2 && men!=3){ // iterate if men value doesn't equal to 1 and 2 and 3
        cout<<"invalid choice"<<endl;
        cout<<"Do you want to cipher string as characters or binary digits"<<endl;
        cout<<"1:cipher to characters"<<endl;
        cout<<"2:cipher to binary digits"<<endl;
        cout<<"3:both"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>men;
        if(men==1||men==2||men==3){ // check if men equals to 1 or 2 or 3
            return men; // return value of men to use it again
            break;
        }
        else{ // check if user's input doesn't equal to 1 or 2 or 3
            continue; // iterate the loop again
        }
    }
    return men; // return value of men to use it again
}
int menu_decipher(){
    cout<<"Do you want to decipher string by entring characters or binary"<<endl;
    cout<<"1:decipher by using characters"<<endl;
    cout<<"2:decipher by using binary digits"<<endl;
    int men;
    cout<<"choose between 1&2: "<<endl;
    cin>>men;
    while(men!=1 && men!=2){ // iterate when value of men doesn't equal 1 and 2
        cout<<"Do you want to decipher string by entring characters or binary"<<endl;
        cout<<"1:decipher by using characters"<<endl;
        cout<<"2:decipher by using binary digits"<<endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin>>men;
        if(men==1||men==2){ // check if men equals to 1 or 2
            return men; // return value of men to use it again
            break;
        }
        else{ // check if men doesn't equal to 1 and 2
            continue; // iterate loop again
        }
    }
    return men; // return value of men to use it again
}
string inp() {
    string input;
    bool validInput = false;

    while (!validInput) { // iterate when not value of valid input is true
        cout << "Enter a string: " << endl;
        cin >> ws; // Skip leading whitespace
        getline(cin, input, '\n');
        bool containsNumber = false;
        for (char chr : input) { // iterate on indexes of input
            if (isdigit(chr)) { // check if this index is digit or not
                containsNumber = true;
                break; // break the loop
            }
        }

        if (!containsNumber) { // check if value of containsNumber is true or not
            validInput = true;
        } else { // check if value of containsNumber is false or not
            cout << "Invalid input. Please enter a string without numbers." << endl;
        }
    }

    string alphabeticOnly = characters(input); // make a valid string
    return alphabeticOnly; // return value of alphabeticOnly to use it again
}
string inp_2() {
    string input;
    bool validInput = false;
    string after_delete;
    while (!validInput) { // iterate when not value of valid input is true
        cout << "Enter a string containing only 'a' and 'b', with a length that is a multiple of 5: " << endl;
        cin >> ws; // Skip leading whitespace
        getline(cin, input);
        after_delete = "";
        for (char chr : input) { // iterate on indexes of input
            if (chr != ' ') { // check if chr equals to space or not
                after_delete += tolower(chr);
            }
        }
        validInput = true;
        if (after_delete.size() % 5 != 0) { // check if size of after_delete modulas 5 equals to 0 or not
            validInput = false;
        }
        for (char chr : after_delete) { // iterate on indexes of after_delete
            if (tolower(chr) != 'a' && tolower(chr) != 'b') { // check if chr doesn't equal to a and b
                validInput = false;
                break; // stop iteration
            }
        }

        if (!validInput || !is_correct_ab(after_delete)) { // check if valid input is true or not
            cout << "Invalid input. Please enter a string containing only 'a' and 'b' and has a length that is a multiple of 5." << endl;
            return inp_2();
        }
    }


    return after_delete; // return value of after_delete to use it again
}
string inp_3() {
    string input;
    bool validInput = false;
    string after_delete = "";
    while (!validInput) { // iterate when not value of valid input is true
        cout << "Enter a string containing only '0' and '1', with a length that is a multiple of 5: " << endl;
        cin >> ws; // Skip leading whitespace
        getline(cin, input);
        after_delete = "";
        for (char chr : input) { // iterate on indexes of input
            if (chr != ' ') { // check if chr equals to space or not
                after_delete += chr;
            }
        }
        validInput = true;
        if (after_delete.size() % 5 != 0) { // check if size of after_delete modulas 5 equals to 0 or not
            validInput = false;
        }
        for (char chr : after_delete) { // iterate on indexes of after_delete
            if (chr != '0' && chr != '1') { // check if chr doesn't equal to 0 and 1
                validInput = false;
                break; // stop the loop
            }
        }
        if (!validInput || !is_correct_10(after_delete)) { // check if valid input is true or not
            cout << "Invalid input. Please enter a string containing only '0' and '1' and has a length that is a multiple of 5." << endl;
            return inp_3();
        }


    }

    return after_delete; // return value of after_delete to use it again
}
string ciphered_1(string decipher){
    string after="";
    int counter = decipher.size();
    for(int index=0;index<=counter;index++){ // iterate on indexes of decipher
        if(toupper(char(decipher[index]))== 'A'){
            after+="aaaaa ";
        }
        else if(toupper(char(decipher[index]))== 'B'){
            after+="aaaab ";
        }
        else if(toupper(char(decipher[index]))== 'C'){
            after+="aaaba ";
        }
        else if(toupper(char(decipher[index]))== 'D'){
            after+="aaabb ";
        }
        else if(toupper(char(decipher[index]))== 'E'){
            after+="aabaa ";
        }
        else if(toupper(char(decipher[index]))== 'F'){
            after+="aabab ";
        }
        else if(toupper(char(decipher[index]))== 'G'){
            after+="aabba ";
        }
        else if(toupper(char(decipher[index]))== 'H'){
            after+="aabbb ";
        }
        else if(toupper(char(decipher[index]))== 'I'){
            after+="abaaa ";
        }
        else if(toupper(char(decipher[index]))== 'J'){
            after+="abaab ";
        }
        else if(toupper(char(decipher[index]))== 'K'){
            after+="ababa ";
        }
        else if(toupper(char(decipher[index]))== 'L'){
            after+="abaab ";
        }
        else if(toupper(char(decipher[index]))== 'M'){
            after+="abbaa ";
        }
        else if(toupper(char(decipher[index]))== 'N'){
            after+="abbab ";
        }
        else if(toupper(char(decipher[index]))== 'O'){
            after+="abbba ";
        }
        else if(toupper(char(decipher[index]))== 'P'){
            after+="abbbb ";
        }
        else if(toupper(char(decipher[index]))== 'Q'){
            after+="baaaa ";
        }
        else if(toupper(char(decipher[index]))== 'R'){
            after+="baaab ";
        }
        else if(toupper(char(decipher[index]))== 'S'){
            after+="baaba ";
        }
        else if(toupper(char(decipher[index]))== 'T'){
            after+="baabb ";
        }
        else if(toupper(char(decipher[index]))== 'U'){
            after+="babaa ";
        }
        else if(toupper(char(decipher[index]))== 'V'){
            after+="babab ";
        }
        else if(toupper(char(decipher[index]))== 'W'){
            after+="babba ";
        }
        else if(toupper(char(decipher[index]))== 'X'){
            after+="babbb ";
        }
        else if(toupper(char(decipher[index]))== 'Y'){
            after+="bbaaa ";
        }
        else if(toupper(char(decipher[index]))== 'Z'){
            after+="bbaab ";
        }
    }
    return after;
}
string ciphered_2(string decipher){
    string after_string="";
    int counter = decipher.size()+1;
    for(int index = 0;index<=counter;index++){ // iterate on indexes of decipher
        if(toupper(char(decipher[index]))== 'A'){
            after_string+="00000 ";
        }
        else if(toupper(char(decipher[index]))== 'B'){
            after_string+="00001 ";
        }
        else if(toupper(char(decipher[index]))== 'C'){
            after_string+="00010 ";
        }
        else if(toupper(char(decipher[index]))== 'D'){
            after_string+="00011 ";
        }
        else if(toupper(char(decipher[index]))== 'E'){
            after_string+="00100 ";
        }
        else if(toupper(char(decipher[index]))== 'F'){
            after_string+="00101 ";
        }
        else if(toupper(char(decipher[index]))== 'G'){
            after_string+="00110 ";
        }
        else if(toupper(char(decipher[index]))== 'H'){
            after_string+="00111 ";
        }
        else if(toupper(char(decipher[index]))== 'I'){
            after_string+="01000 ";
        }
        else if(toupper(char(decipher[index]))== 'J'){
            after_string+="01001 ";
        }
        else if(toupper(char(decipher[index]))== 'K'){
            after_string+="01010 ";
        }
        else if(toupper(char(decipher[index]))== 'L'){
            after_string+="01011 ";
        }
        else if(toupper(char(decipher[index]))== 'M'){
            after_string+="01100 ";
        }
        else if(toupper(char(decipher[index]))== 'N'){
            after_string+="01101 ";
        }
        else if(toupper(char(decipher[index]))== 'P'){
            after_string+="01110 ";
        }
        else if(toupper(char(decipher[index]))== 'Q'){
            after_string+="10000 ";
        }
        else if(toupper(char(decipher[index]))== 'R'){
            after_string+="10001 ";
        }
        else if(toupper(char(decipher[index]))== 'S'){
            after_string+="10010 ";
        }
        else if(toupper(char(decipher[index]))== 'T'){
            after_string+="10011 ";
        }
        else if(toupper(char(decipher[index]))== 'U'){
            after_string+="10100 ";
        }
        else if(toupper(char(decipher[index]))== 'V'){
            after_string+="10101 ";
        }
        else if(toupper(char(decipher[index]))== 'W'){
            after_string+="10110 ";
        }
        else if(toupper(char(decipher[index]))== 'X'){
            after_string+="10111 ";
        }
        else if(toupper(char(decipher[index]))== 'Y'){
            after_string+="11000 ";
        }
        else if(toupper(char(decipher[index]))== 'Z'){
            after_string+="11001 ";
        }

    }
    return after_string;
}
string deciphered_1(string cipher){
    string after_string="";
    int counter = cipher.size()+1;
    for(int index = 0;index<=counter;index+=5){ // iterate on indexes of decipher
        string temporary = cipher.substr(index,5); // make substring every 5 characters
        if(temporary=="aaaaa"){
            after_string+="a";
        }
        if(temporary=="aaaab"){
            after_string+="b";
        }
        if(temporary=="aaaba"){
            after_string+="c";
        }
        if(temporary=="aaabb"){
            after_string+="d";
        }
        if(temporary=="aabaa"){
            after_string+="e";
        }
        if(temporary=="aabab"){
            after_string+="f";
        }
        if(temporary=="aabba"){
            after_string+="g";
        }
        if(temporary=="aabbb"){
            after_string+="h";
        }
        if(temporary=="abaaa"){
            after_string+="i";
        }
        if(temporary=="abaab"){
            after_string+="j";
        }
        if(temporary=="ababa"){
            after_string+="k";
        }
        if(temporary=="ababb"){
            after_string+="l";
        }
        if(temporary=="abbaa"){
            after_string+="m";
        }
        if(temporary=="abbab"){
            after_string+="n";
        }
        if(temporary=="abbba"){
            after_string+="o";
        }
        if(temporary=="abbbb"){
            after_string+="p";
        }
        if(temporary=="baaaa"){
            after_string+="q";
        }
        if(temporary=="baaab"){
            after_string+="r";
        }
        if(temporary=="baaba"){
            after_string+="s";
        }
        if(temporary=="baabb"){
            after_string+="t";
        }
        if(temporary=="babaa"){
            after_string+="u";
        }
        if(temporary=="babab"){
            after_string+="v";
        }
        if(temporary=="babba"){
            after_string+="w";
        }
        if(temporary=="babbb"){
            after_string+="x";
        }
        if(temporary=="bbaaa"){
            after_string+="y";
        }
        if(temporary=="bbaab"){
            after_string+="z";
        }
    }
    return after_string;
}
string deciphered_2(string cipher){
    string after_string="";
    int counter = cipher.size()+1;
    for(int index = 0;index<=counter;index+=5){ // iterate on indexes of cipher
        string temporary = cipher.substr(index,5); // make substring every 5 characters
        if(temporary=="00000"){
            after_string+="a";
        }
        if(temporary=="00001"){
            after_string+="b";
        }
        if(temporary=="00010"){
            after_string+="c";
        }
        if(temporary=="00011"){
            after_string+="d";
        }
        if(temporary=="00100"){
            after_string+="e";
        }
        if(temporary=="00101"){
            after_string+="f";
        }
        if(temporary=="00110"){
            after_string+="g";
        }
        if(temporary=="00111"){
            after_string+="h";
        }
        if(temporary=="01000"){
            after_string+="i";
        }
        if(temporary=="01001"){
            after_string+="j";
        }
        if(temporary=="01010"){
            after_string+="k";
        }
        if(temporary=="01011"){
            after_string+="l";
        }
        if(temporary=="01100"){
            after_string+="m";
        }
        if(temporary=="01101"){
            after_string+="n";
        }
        if(temporary=="01110"){
            after_string+="o";
        }
        if(temporary=="01111"){
            after_string+="p";
        }
        if(temporary=="10000"){
            after_string+="q";
        }
        if(temporary=="10001"){
            after_string+="r";
        }
        if(temporary=="10010"){
            after_string+="s";
        }
        if(temporary=="10011"){
            after_string+="t";
        }
        if(temporary=="10100"){
            after_string+="u";
        }
        if(temporary=="10101"){
            after_string+="v";
        }
        if(temporary=="10110"){
            after_string+="w";
        }
        if(temporary=="10111"){
            after_string+="x";
        }
        if(temporary=="11000"){
            after_string+="y";
        }
        if(temporary=="11001"){
            after_string+="z";
        }
    }
    return after_string;
}

bool is_correct_10(string cipher) {
    int counter = cipher.size();
    for (int index = 0; index < counter; index += 5) {
        string temporary = cipher.substr(index, 5);
        if (temporary != "00000" &&
            temporary != "00001" &&
            temporary != "00010" &&
            temporary != "00011" &&
            temporary != "00100" &&
            temporary != "00101" &&
            temporary != "00110" &&
            temporary != "00111" &&
            temporary != "01000" &&
            temporary != "01001" &&
            temporary != "01010" &&
            temporary != "01011" &&
            temporary != "01100" &&
            temporary != "01101" &&
            temporary != "01110" &&
            temporary != "01111" &&
            temporary != "10000" &&
            temporary != "10001" &&
            temporary != "10010" &&
            temporary != "10011" &&
            temporary != "10100" &&
            temporary != "10101" &&
            temporary != "10110" &&
            temporary != "10111" &&
            temporary != "11000" &&
            temporary != "11001") {
            return false;
        }
    }
    return true;
}
bool is_correct_ab(string cipher) {
    int counter = cipher.size();
    for (int index = 0; index < counter; index += 5) {
        string temporary = cipher.substr(index, 5);
        if (temporary != "aaaaa" &&
            temporary != "aaaab" &&
            temporary != "aaaba" &&
            temporary != "aaabb" &&
            temporary != "aabaa" &&
            temporary != "aabab" &&
            temporary != "aabba" &&
            temporary != "aabbb" &&
            temporary != "abaaa" &&
            temporary != "abaab" &&
            temporary != "ababa" &&
            temporary != "ababb" &&
            temporary != "abbaa" &&
            temporary != "abbab" &&
            temporary != "abbba" &&
            temporary != "abbbb" &&
            temporary != "baaaa" &&
            temporary != "baaab" &&
            temporary != "baaba" &&
            temporary != "baabb" &&
            temporary != "babaa" &&
            temporary != "babab" &&
            temporary != "babba" &&
            temporary != "babbb" &&
            temporary != "bbaaa" &&
            temporary != "bbaab") {
            return false;
        }
    }
    return true;
}

int simple_substitution(string msg){
    // getting user's choice for encryption/decryption
    string choice;
    cout<<"Welcome, what would you like to do today?"<<endl;
    cout<<"1. Cipher a message"<<endl;
    cout<<"2. Decipher a message"<<endl;
    cout<<"3. exit"<<endl;
    cout<<"Please enter 1 or 2 or 3: "<<endl;

    cin>>choice;

    // making sure of validity of choice
    while(true) {
        if(choice=="1")break;
        else if(choice=="2")break;
        else if(choice=="3"){
            cout<<"Thanks for using our Program"<<endl;
            exit(0) ;}
        else{
            cout<<"Please enter a valid choice: "<<endl;

            cin>>choice;
        }
    }

    //cipher part
    if(choice=="1"){
        // declaring key and inputting it
        string key;
        cout<<"Please enter a key of five unique letters without spaces: "<<endl;
        getline(cin,key);
        getline(cin,key);

        //validating key
        bool flag2=false;
        while(!flag2){
            for(int i=0; i<key.length(); i++){
                while(key.length()!=5){
                    flag2= false;
                    cout<<"Please enter a key of five unique letters without spaces: "<<endl;

                    getline(cin,key);
                }
                while(!isalpha(key[i])){
                    flag2= false;
                    cout<<"Please enter a key of five unique letters without spaces: "<<endl;

                    getline(cin,key);
                }
                for(int j=0; j<key.length(); j++){
                    for(int k=j+1; k<key.length(); k++){
                        if(key[k]==key[j]){
                            flag2= false;
                            cout<<"Please enter a key of five unique letters without spaces: "<<endl;

                            getline(cin,key);
                        }
                    }
                }
            }
            flag2=true;
        }

        // lowercase key
        for(int i=0; i<key.length(); i++){
            key[i]= tolower(key[i]);
        }

        // lowercase msg
        for(int i=0; i<msg.length(); i++){
            msg[i]= tolower(msg[i]);
        }

        // declare alphabet string and cipher (add key to start of cipher)
        string alphabet="abcdefghijklmnopqrstuvwxyz";
        string cipher=key;

        // add the rest of the alphabet to cipher and make sure no letters are repeated
        for(int i=0; i<alphabet.length(); i++){
            if(alphabet[i]!=key[0]&&alphabet[i]!=key[1]&&alphabet[i]!=key[2]&&alphabet[i]!=key[3]&&alphabet[i]!=key[4]){
                cipher+=alphabet[i];
            }
        }

        // loop on each index of msg, compare it with alphabet and change it with corresponding index in cipher
        for(int i=0; i<msg.length(); i++){
            for(int j=0; j<alphabet.length(); j++){
                if(msg[i]==alphabet[j]){
                    msg[i]=cipher[j];
                    break;
                }
            }
        }

        // output ciphered msg
        if(choice=="1"){
            cout<<"Your encrypted message is: "<<endl;
            cout<<msg;
        }

    }

        // decipher part
    else if(choice=="2"){
        // declaring key and inputting it
        string key;
        cout<<"Please enter a key of five unique letters without spaces: "<<endl;
        getline(cin,key);
        getline(cin,key);

        //validating key
        bool flag2=false;
        while(!flag2){
            for(int i=0; i<key.length(); i++){
                while(key.length()!=5){
                    flag2= false;
                    cout<<"Please enter a key of five unique letters without spaces: "<<endl;

                    getline(cin,key);
                }
                while(!isalpha(key[i])){
                    flag2= false;
                    cout<<"Please enter a key of five unique letters without spaces: "<<endl;

                    getline(cin,key);
                }
                for(int j=0; j<key.length(); j++){
                    for(int k=j+1; k<key.length(); k++){
                        if(key[k]==key[j]){
                            flag2= false;
                            cout<<"Please enter a key of five unique letters without spaces: "<<endl;

                            getline(cin,key);
                        }
                    }
                }
            }
            flag2=true;
        }

        // lowercase key
        for(int i=0; i<key.length(); i++){
            key[i]= tolower(key[i]);
        }

        // lowercase msg
        for(int i=0; i<msg.length(); i++){
            msg[i]= tolower(msg[i]);
        }

        // declare alphabet string and cipher (add key to start of cipher)
        string alphabet="abcdefghijklmnopqrstuvwxyz";
        string cipher=key;

        // add the rest of the alphabet to cipher and make sure no letters are repeated
        for(int i=0; i<alphabet.length(); i++){
            if(alphabet[i]!=key[0]&&alphabet[i]!=key[1]&&alphabet[i]!=key[2]&&alphabet[i]!=key[3]&&alphabet[i]!=key[4]){
                cipher+=alphabet[i];
            }
        }

        // loop on each index of msg, compare it with cipher and change it with corresponding index in alphabet
        for(int i=0; i<msg.length(); i++){
            for(int j=0; j<alphabet.length(); j++){
                if(msg[i]==cipher[j]){
                    msg[i]=alphabet[j];
                    break;
                }
            }
        }
        if(choice=="2"){
            cout<<"Your decrypted message is: "<<endl;
            cout<<msg;
        }
    }
    cout<<endl<<endl;
    string choice_ctn;
    cout<<"If you would like to continue, enter A"<<endl;
    cout<<"If you don't want to continue, enter B"<<endl;
    cin >> choice_ctn;
    while (true) {
        if (choice_ctn == "A") main();
        else if (choice_ctn == "B"){
            cout<<"Thank you for using this program"<<endl;
            exit(0);
        }
        else {
            cout << "Please enter a valid choice: " << endl;
            cin >> choice_ctn;
        }
    }
}

int Rail_fence(string msg){
    // getting user's choice for encryption/decryption
    string choice;
    cout<<"Welcome, what would you like to do today?"<<endl;
    cout<<"1. Cipher a message"<<endl;
    cout<<"2. Decipher a message"<<endl;
    cout<<"3. exit"<<endl;
    cout<<"Please enter 1 or 2 or 3: "<<endl;
    cin>>choice;

    // making sure of validity of choice
    while(true) {
        if(choice=="1")break;
        else if(choice=="2")break;
        else if(choice=="3"){
            cout<<"Thanks for using our program"<<endl;
            exit(0) ;}
        else{
            cout<<"Please enter a valid choice: "<<endl;
            cin>>choice;
        }
    }

    // encryption part
    // counting number of letters in the word without spaces, numbers and punctuation marks
    if(choice=="1"){
        long long counter=0;
        for(int i=0; i<msg.length(); i++){
            if(isalpha(msg[i])){
                counter++;
            }
        }

        // declaring holder array
        string holder[counter];
        long long l=0;

        // getting rid of , numbers and punctuation marks between words and adding the rest to holder string
        for(long long i=0; i<msg.length(); i++){
            if(isspace(msg[i])){continue;}
            else if(isdigit(msg[i])){ continue;}
            else if(ispunct(msg[i])){ continue;}
            else if(isalpha(msg[i])){
                holder[l]=msg[i];
                l+=1;

            }
        }

        // declaring three empty strings and long long j for determining if the encrypted message reached original length
        long long j=0;
        string arr1="";
        string arr2="";
        string arr3="";

        while(true){
            // pattern of rail fence
            // first letter in first row
            arr1+=holder[j];
            j++;
            // second letter in second row
            if(j>=counter){break;}
            arr2+=holder[j];
            j++;
            // third letter in third row
            if(j>=counter){break;}
            arr3+=holder[j];
            j++;
            // fourth letter in second row,and then we repeat the same process until all letters are filled in the string
            if(j>=counter){break;}
            arr2+=holder[j];
            j++;
            if(j>=counter){break;}
        }

        // printing out encrypted message
        cout<<endl;
        cout<<"Your encrypted message: "<<endl;
        cout<<arr1<<arr2<<arr3;
    }

        // decryption part
        // counting number of letters in the word without spaces, numbers and punctuation marks
    else if(choice=="2"){
        long long counter=0;
        for(int i=0; i<msg.length(); i++){
            if(isalpha(msg[i])){
                counter++;
            }
        }

        // Declaring holder array
        string holder[counter];

        // getting rid of spaces, numbers and punctuation marks between words and adding the rest to holder string
        long long l=0;
        for(long long i=0; i<msg.length(); i++){
            if(isspace(msg[i])){continue;}
            else if(isdigit(msg[i])){ continue;}
            else if(ispunct(msg[i])){ continue;}
            else if(isalpha(msg[i])){
                holder[l]=msg[i];
                l+=1;

            }
        }

        // setting up array of rail fence cipher
        string arr[3][counter];
        for(int i=0; i<3; i++){
            for(int j=0; j<counter; j++){
                arr[i][j]="_";
            }
            cout<<endl;
        }

        // putting # in the places where the letters will be
        for(int i=0; i<1; i++){
            for(int j=0; j<counter; j+=4){
                arr[0][j]="#";

            }
        }
        for(int i=1; i<2; i++){
            for(int j=1; j<counter; j+=2){
                arr[1][j]="#";
            }
        }
        for(int i=2; i<3; i++){
            for(int j=2; j<counter; j+=4){
                arr[2][j]="#";
            }
        }

        // declaring three string to rearrange letters
        string msg1="";
        string msg2="";
        string msg3="";
        long long counter2=0;

        // adding letters in first row to msg1
        for(long long i=0; i<counter; i++){
            for(int j=0; j<counter; j++){
                if(arr[0][j]=="#"){
                    arr[0][j]=holder[i];
                    msg1+=holder[i];
                    counter2++;
                    break;
                }
            }
        }

        // adding letters in second row to msg2
        for(long long i=counter2; i<counter; i++){
            for(int j=0; j<counter; j++){
                if(arr[1][j]=="#"){
                    arr[1][j]=holder[i];
                    msg2+=holder[i];
                    counter2++;
                    break;
                }
            }
        }

        // adding letters in third row to msg3
        for(long long i=counter2; i<counter; i++){
            for(int j=0; j<counter; j++){
                if(arr[2][j]=="#"){
                    arr[2][j]=holder[i];
                    msg3+=holder[i];
                    counter2++;
                    break;
                }
            }
        }

        // declaring final msg which will be arranged correctly
        string final_msg="";
        long long k=0;
        long long x=0;

        while(final_msg.length()<counter){
            // pattern to combine all letters in the correct order
            // taking letter from first array then second then third then second and repeating this pattern until length of final msg equals counter
            final_msg+=msg1[k];
            if(final_msg.length()==counter)break;
            final_msg+=msg2[x];
            x++;
            if(final_msg.length()==counter)break;
            final_msg+=msg3[k];
            k++;
            if(final_msg.length()==counter)break;
            final_msg+=msg2[x];
            x++;
            if(final_msg.length()==counter)break;


        }
        // printing final msg
        cout<<"Your decrypted message is: "<<endl<<final_msg<<endl;

    }
    cout<<endl<<endl;
    string choice_ctn;
    cout<<"If you would like to continue, enter A"<<endl;
    cout<<"If you don't want to continue, enter B"<<endl;
    cin >> choice_ctn;
    while (true) {
        if (choice_ctn == "A") main();
        else if (choice_ctn == "B"){
            cout<<"Thank you for using this program"<<endl;
            exit(0);
        }
        else {
            cout << "Please enter a valid choice: " << endl;
            cin >> choice_ctn;
        }
    }

}
// function that ignores special characters and numbers and adds the rest to a string
string substitution_checker(string msg){
    long long counter=0;
    string msg_after="";
    for(int i=0; i<msg.length(); i++){
        if(isalpha(msg[i])){
            msg_after+=msg[i];
            counter++;
        }
        else if(isspace(msg[i])){
            msg_after+=msg[i];
        }
    }
    if(counter==0){
        cout<<"Please enter a valid message containing alphabets: "<<endl;
        getline(cin,msg);
        return substitution_checker(msg);
    }
    else{
        return msg_after;
    }
}
void route_main(){
    // get msg from user, validate it and make all the letters uppercase with removing spaces and numbers and special characters
    string msg;
    cout<<"Please enter your message whose length is greater than 2 "<<endl;
    cin.ignore();
    getline(cin,msg);
    msg=ignore_statement_route(msg);
    for(int i=0; i<msg.length(); i++){
        msg[i]= toupper(msg[i]);
    }
    Route_Cipher(msg);
}
string ignore_statement_route(string before){
//    to ignore anything otherwise alphabetic and return only alphabetic characters and check that length is greater than 2
    string after;
    for (int i = 0; i < before.size(); ++i) {
        if (isalpha(before[i])){
            after += before[i];
        }
    }
    if(after.empty()|| after.length()<3){
        cout<<"Please enter a message whose length is greater than 2"<<endl;
        getline(cin,before);
        return ignore_statement_route(before);
    }
    return after;
}
// function that checks validity of key
bool key_check(string key){
    for(int i=0; i<key.length(); i++){
        if(!isdigit(key[i])){
            return false;
        }
    }
    return true;
}
int Route_Cipher( string msg) {
    // Getting user's choice for encryption/decryption
    string choice;
    cout << "Welcome, what would you like to do today?" << endl;
    cout << "1. Cipher a message" << endl;
    cout << "2. Decipher a message" << endl;
    cout << "3. Exit" << endl;
    cout << "Please enter 1 or 2 or 3: "<<endl;
    cin >> choice;

    // Making sure of the validity of the choice
    while (true) {
        if (choice == "1" || choice == "2" || choice == "3") {
            break;
        } else {
            cout << "Please enter a valid choice: "<<endl;
            cin >> choice;
        }
    }
    // encryption
    if (choice == "1") {
        // inputting key
        string key;
        cout << "Please enter key (from 2 to half the length of the message): "<<endl;
        cin >> key;
        // checking validity of key
        double mx=(double)(msg.length()/2.0);
        while(true){
            if(key_check(key)&& stoi(key)>1 && stoi(key)<=ceil(mx)){
                break;
            }
            else{
                cout << "Please enter a valid key(from 2 to half the length of the message): "<<endl;
                cin >> key;
            }
        }
        // calculating number of rows and columns
        long long columns = stoi(key);
        long long rows = (msg.length() + columns - 1) / columns;
        // creating the 2d vector array and initializing all indexes with '-' to put the letters in it
        vector<vector<char>> arr(rows, vector<char>(columns, '-'));

        // putting letters in the vector
        long long k = 0;
        for (long long i = 0; i < rows; ++i) {
            for (long long j = 0; j < columns; ++j) {
                if (k < msg.length()) {
                    arr[i][j] = msg[k++];
                }
            }
        }
        // if there is empty space in a row which has letters fill the rest of the spaces with X
        if(isalpha(arr[rows-1][0])){
            for(int i=rows-1; i<rows; i++){
                for(int j=1; j<columns; j++){
                    if(arr[rows-1][j]=='-'){
                        arr[rows-1][j]='X';
                    }
                }
            }
        }
        //  getting count of rows and columns to loop
        long long rows_count=rows;
        long long columns_count=columns;

        long long counter=0;
        // looping until counter =0
        while(counter<columns_count*rows_count){
            // looping on the last column from top right to bottom right, outputting each index from the top right till downwards and remove column
            for(long long i=0; i<rows; i++){

                cout<<arr[i][columns-1];
                arr[i].erase(arr[i].begin()+(columns-1));
                counter++;
            }
            // check if arr is empty or rows or columns are empty
            --columns;
            if(arr.empty() || rows==0 || columns==0){
                break;
            }


            // looping on last row from bottom right till bottom left and outputting each index with removing row
            for(long long i=columns-1; i>=0; i--){

                cout<<arr[rows-1][i];
                counter++;

            }


            arr.pop_back();
            --rows;
            // check if arr is empty or rows or columns are empty
            if(arr.empty() || rows==0 || columns==0){
                break;
            }

            // looping on first column from bottom left to top left with outputting result and removing column
            for(long long i=rows-1; i>=0; i--){

                cout<<arr[i][0];
                arr[i].erase(arr[i].begin());
                counter++;
            }

            --columns;
            // check if arr is empty or rows or columns are empty
            if(arr.empty() || rows==0 || columns==0){
                break;
            }
            // looping on first row from top left to top right to complete spiral, output each index and remove row
            for(long long i=0; i<columns; i++){

                cout<<arr[0][i];
                counter++;
            }

            arr.erase(arr.begin());
            --rows;
            // check if arr is empty or rows or columns are empty
            if(arr.empty() || rows==0 || columns==0){
                break;
            }

        }
        // checking if user wants to continue
        cout<<endl<<endl;
        string choice_ctn;
        cout<<"If you would like to continue, enter A"<<endl;
        cout<<"If you don't want to continue, enter B"<<endl;
        cin >> choice_ctn;
        while (true) {
            if (choice_ctn == "A") {
                cin.ignore();
                main();
            }
            else if (choice_ctn == "B"){
                cout<<"Thanks for using our program"<<endl;
                exit(0);
            }
            else {
                cout << "Please enter a valid choice: " << endl;
                cin >> choice_ctn;
            }
        }

    }
    else if(choice=="2"){
        // inputting key
        string key;
        cout << "Please enter key (from 2 to half the length of the message): "<<endl;
        cin >> key;
        double mx=(double)(msg.length()/2.0);
        // checking validity of key
        while(true){
            if(key_check(key)&& stoi(key)>1 && stoi(key)<=ceil(mx)){
                break;
            }
            else{
                cout << "Please enter a valid key(from 2 to half the length of the message): "<<endl;
                cin >> key;
            }
        }


        // calculating number of rows and columns
        long long columns = stoll(key);
        long long rows = (msg.length() + columns - 1) / columns;
        // creating the 2d vector array and initializing all indexes with '-' to put the letters in it
        vector<vector<char>> arr(rows, vector<char>(columns, 'X'));
        //  getting count of rows and columns to loop
        long long rows_down=rows;
        long long columns_right=columns;
        long long k=0;
        bool flag= false;
        if(stoi(key)>=3 && msg.length()<stoi(key))flag= true;
        long long columns_left=0;
        long long rows_up=0;
        // 2 by 2 array if message length = 3 or 4
        if(stoi(key)==2 && msg.length()<=4){
            k=0;
            while(true){
                arr[0][1]=msg[k];
                k++;
                if(k>msg.length()-1)break;
                arr[1][1]=msg[k];
                k++;
                if(k>msg.length()-1)break;
                arr[1][0]=msg[k];
                k++;
                if(k>msg.length()-1)break;
                arr[0][0]=msg[k];
                k++;
                if(k>msg.length()-1)break;
            }
            // outputting message
            cout<<endl;
            cout<<endl;
            cout<<"Your deciphered message is: "<<endl;
            for(long long i=0; i<rows; i++){
                for(long long j=0; j<columns; j++){
                    cout<<arr[i][j];
                }

            }

        }
        else {
            // loop until k reaches last index of string
            while (k <= msg.length() - 1) {
                // check if the previous condition was true so break loop
                if ((rows == 2 || rows == 1) && columns == 2)break;
                // for every loop check if k reached last index
                if (k > msg.length() - 1)break;
                // start from right column and fill vector
                for (long long i = rows_up; i < rows_down; i++) {
                    arr[i][columns_right - 1] = msg[k];
                    k++;

                }
                if (k > msg.length() - 1)break;
                // move to the left, so we don't loop on same column
                columns_right--;

                // loop on bottom row and fill vector
                for (long long i = columns_right - 1; i >= columns_left; i--) {
                    arr[rows_down - 1][i] = msg[k];
                    k++;
                }
                if (k > msg.length() - 1)break;
                // move upwards so we don't loop on same row
                rows_down--;

                // loop on left column and fill vector
                for (long long i = rows_down - 1; i >= rows_up; i--) {
                    arr[i][columns_left] = msg[k];
                    k++;
                }
                if (k > msg.length() - 1)break;
                // move rightwards to avoid looping on same column
                columns_left++;

                // looping on upper row and fill vector
                for (long long i = columns_left; i <= columns_right - 1; i++) {
                    arr[rows_up][i] = msg[k];
                    k++;
                }
                if (k > msg.length() - 1)break;
                // move downwards to avoid looping on same row
                rows_up++;
            }
            cout<<endl;
            cout<<endl;
            cout<<"Your deciphered message is: "<<endl;
            // output array row by row
            for(long long i=0; i<rows; i++){
                for(long long j=0; j<columns; j++){
                    cout<<arr[i][j];

                }

            }

        }
        // check if user wants to continue or not
        cout<<endl<<endl;
        string choice_ctn;
        cout<<"If you would like to continue, enter A"<<endl;
        cout<<"If you don't want to continue, enter B"<<endl;
        cin >> choice_ctn;
        while (true) {
            if (choice_ctn == "A") {
                cin.ignore();
                main();
            }
            else if (choice_ctn == "B"){
                cout<<"Thanks for using our program"<<endl;
                exit(0);
            }
            else {
                cout << "Please enter a valid choice: " << endl;
                cin >> choice_ctn;
            }
        }


    }

        // exit program
    else{
        cout<<"Thanks for using our program"<<endl;
        exit(0);
    }
}
void XOR_cipher(){
    cout << "*** Welcome to XOR cipher ***\n";
    string statement, keyword, choice;
    // Asking the user to choose an option
    cout << "Please choose\n1 to enter the cipher\n2 to decipher\n3 to exit\n";
    cin >> choice;
    // Validating the user's choice
    while (!(choice == "1" || choice == "2" || choice == "3")) {
        cout << "Invalid input. Please choose\n1 to enter the cipher\n2 to decipher\n3 to exit\n";
        cin >> choice;
    }

    cin.ignore(); // Clearing input buffer

    // choose between cipher or decipher or exit
    if (choice == "1"){
//        here I will take the key then convert it to ascii code then to binary
        // declare the ascii code and the ascii key
        bool notLetter = false;
        string encrypted_text, encrypted_hex;
        string key;
        cout << "Enter the security key" << endl;
        cin >> key;
        // This part will ask for the key again if it is not a character by ignoring anything otherwise characters then check
        for (char i : key) {
            if (!isalpha(i)){
                notLetter = true;
                break;
            }
        }
        while(notLetter){
            cout << "Invalid input. Please enter a valid key (It must be letters)" << endl;
            cin >> key;
            // This part will ask for the key again if it is not a character by ignoring anything otherwise characters then check
            notLetter = false;
            for (char i : key) {
                if (!isalpha(i)){
                    notLetter = true;
                    break;
                }
            }
        }
        cout << "Enter the statement" << endl;
        cin.ignore();
        getline(cin,statement);
        // get the input again if the input is all does not include and characters
        while(statement.empty()){
            cout << "Invalid input. please enter a valid statement" << endl;
            cin.ignore();
            getline(cin,statement);

        }

        //cipher the text by Xor and Hexadecimal by getting the ascii code for every character
        int j = 0;
        for (char i : statement) {
            stringstream ss;
            encrypted_text += (char)(key[j]^i);
            ss << hex << setw(2) << setfill('0') << (int)(key[j] ^ i);
            encrypted_hex += ss.str() + " ";
            j = ++j % key.size(); // to repeat on the key again
        }
        // ignore anything otherwise digits and alphabets and white spaces then print the massage
        encrypted_text = ignore_statement_XOR(encrypted_text);
        cout << "Cipher text: " << encrypted_text << endl;
        cout << "Cipher by hexadecimal: " << encrypted_hex << endl;
    }else if (choice == "2"){
        int temp_ascii;
        bool notLetter = false,notHex;
        string decrypted_text;
        string key;
        cout << "Enter the security key" << endl;
        cin >> key;
        // This part will ask for the key again if it is not a character by ignoring anything otherwise characters then check
        for (char i : key) {
            if (!isalpha(i)){
                notLetter = true;
                break;
            }
        }
        while(notLetter){
            cout << "Invalid input. Please enter a valid key (It must be letters)" << endl;
            cin >> key;
            // This part will ask for the key again if it is not a character by ignoring anything otherwise characters then check
            notLetter = false;
            for (char i : key) {
                if (!isalpha(i)){
                    notLetter = true;
                    break;
                }
            }
        }
        cout << "Enter the encrypted statement (Hexadecimal code):" << endl;
        cin.ignore();
        getline(cin,statement);
        notHex = check_for_hexadecimal(statement);
        while(notHex || statement.empty()){
            cout << "Invalid input. Please enter a valid encrypted statement (Hexadecimal code):" << endl;
            getline(cin,statement);
            notHex = check_for_hexadecimal(statement);
        }
        // this part will ignore any spaces

        //decipher the Hexadecimal by Xor and text by getting the ascii code for every 2 hexadecimal
        int j = 0;
        for (int i = 0 ; i < statement.size() ; i+=2 ) {
            if(isspace(statement[i])){
                i++;
            }
            temp_ascii = stoi(statement.substr(i, 2), 0, 16);
            decrypted_text += (char)(temp_ascii ^ key[j]);
            j = ++j % key.size(); // to repeat on the key again
        }
        cout << "The decrypted text is: "<< decrypted_text << endl;
    }else{
        cout<<"Thanks for using our program"<<endl;
        exit(0);}

    // print the menu to play again
    cout << "Do you want to play again or exit?\npress\n1 to play XOR cipher again\n2 to return to main menu\n3 to exit\n";
    cin >> choice;
    while (!(choice == "1" || choice == "2" || choice == "3")){
        cout << "Invalid choice. Please press\n1 to play XOR cipher again\n2 to return to main menu\n3 to exit\n";
        cin >> choice;
    }
    if (choice == "1"){
        XOR_cipher();
    }else if (choice == "2"){
        main();
    }else {
        cout<<"Thanks for using our program"<<endl;
        exit(0);
    }
}


bool check_for_hexadecimal(const string& statement) {
    // Iterate through each character in the statement
    for (char c : statement) {
        // i will skip space
        if(isspace(c)){
            continue;
        }
        // Check if the character is not a digit and not a valid hexadecimal character
        if (!isdigit(c) && !(c >= 'A' && c <= 'F') && !(c >= 'a' && c <= 'f')) {
            // If it is not a hexadecimal character then return true
            return true;
        }
    }
    // If all characters are hexadecimal then return false
    return false;
}



void main_vigenere() {
    cout << "*** Welcome to vigenere cipher ***\n";
    string statement, keyword, choice;
    // Asking the user to choose an option
    cout << "Please choose\n1 to enter the cipher\n2 to decipher\n3 to exit\n";
    cin >> choice;
    // Validating the user's choice
    while (!(choice == "1" || choice == "2" || choice == "3")) {
        cout << "Invalid input. Please choose\n1 to enter the cipher\n2 to decipher\n3 to exit\n";
        cin >> choice;
    }

    cin.ignore(); // Clearing input buffer

    // choose between cipher or decipher or exit
    if (choice == "1") {
        // Getting the statement from the user
        cout << "Enter the statement (up to 80 characters):\n";
        do {
            getline(cin, statement);
            // if wrong input print this massage and repeat
            if (statement.size() > 80) { cout << "Please, enter the statement (up to 80 characters):\n"; }
        } while (statement.size() > 80 || statement.empty());

        // Getting the keyword from the user
        cout << "Enter the keyword (up to 8 characters):\n";
        do {
            getline(cin, keyword);
            // if wrong input print this massage and repeat
            if (keyword.size() > 8 || keyword.empty() || !check_for_characters(keyword)) {
                cout << "Please, enter the keyword (up to 8 characters) and it must be alphabetic:\n";
            }
        } while (keyword.size() > 8 || keyword.empty() || !check_for_characters(keyword));

        // Convert statement to uppercase
        for (char& c : statement) {
            c = toupper(c);
        }

        // Repeat the keyword to match the length of the statement
        string repeatedKeyword;
        for (int i = 0; i < statement.length(); ++i) {
            repeatedKeyword += keyword[i % keyword.length()];
        }
        // call Vigenere Cipher
        vigenere_cipher(statement, repeatedKeyword);

    } else if (choice == "2") {
        // Getting the statement from the user
        cout << "Enter the statement (up to 80 characters):\n";
        do {
            getline(cin, statement);
            // if wrong input print this massage and repeat
            if (statement.size() > 80 || statement.empty()) { cout << "Please, enter the statement (up to 80 characters):\n"; }
        } while (statement.size() > 80 || statement.empty());

        // Getting the keyword from the user
        cout << "Enter the keyword (up to 8 characters):\n";
        do {
            getline(cin, keyword);
            // if wrong input print this massage and repeat
            if (keyword.size() > 8 || keyword.empty() || !check_for_characters(keyword)) {
                cout << "Please, enter the keyword (up to 8 characters) and it must be alphabetic:\n";
            }
        } while (keyword.size() > 8 || keyword.empty() || !check_for_characters(keyword));

        // Convert statement to uppercase
        for (char& c : statement) {
            c = toupper(c);
        }

        // Repeat the keyword to match the length of the statement
        string repeatedKeyword;
        for (int i = 0; i < statement.length(); ++i) {
            repeatedKeyword += keyword[i % keyword.length()];
        }
        // Decrypting the statement using Vigenere Cipher
        vigenere_decipher(statement, repeatedKeyword);

    } else {
        cout<<"Thanks for using our program"<<endl;
        exit(0); }
    cout << "Do you want to play again or exit?\npress\n1 to play vigenere cipher again\n2 to return to main menu\n3 to exit\n";
    cin >> choice;
    while (!(choice == "1" || choice == "2" || choice == "3")){
        cout << "Invalid choice. Please press\n1 to play vigenere cipher again\n2 to return to main menu\n3 to exit\n";
        cin >> choice;
    }
    if (choice == "1"){
        main_vigenere();
    }else if (choice == "2"){
        main();
    }else {
        cout<<"Thanks for using our program"<<endl;
        exit(0);}

}

// Function to check if a string contains only alphabetic characters
bool check_for_characters(const string& str) {
    for (char c : str) {
        if (!isalpha(c))
            return false;
    }
    return true;
}

// Function to decipher a message using Vigenere Cipher
void vigenere_decipher(const string& message, const string& keyword) {
    string decryptedMessage;
    int keyword_index = 0;

    for (char c : message) {
        if (isalpha(c)) {
            // to decrypt the char by the key
            char decryptedChar = ((c - 'A') - (toupper(keyword[keyword_index]) - 'A') + 26) % 26 + 'A';
            decryptedMessage += decryptedChar;
            keyword_index = (keyword_index + 1) % keyword.length();
        } else {
            decryptedMessage += c;
            keyword_index = (keyword_index + 1) % keyword.length();
        }
    }

    cout << "Decryption statement is : " << decryptedMessage << endl;
}

// Function to encrypt a statement using Vigenere Cipher
void vigenere_cipher(const string& statement, const string& keyword) {
    string encryptedMessage;
    int keyword_index = 0;

    for (char c : statement) {
        if (isalpha(c)) {
            // to encrypt the char by the key
            char encryptedChar = ((c - 'A') + (toupper(keyword[keyword_index]) - 'A')) % 26 + 'A';
            encryptedMessage += encryptedChar;
            keyword_index = (keyword_index + 1) % keyword.length();
        } else {
            encryptedMessage += c;
            keyword_index = (keyword_index + 1) % keyword.length();
        }
    }
    cout << "Encrypted statement: " << encryptedMessage << endl;
}
void main_affine(){
    cin.ignore();
    cout<<"Welcome to affine Cipher"<<endl;
    string choice = affine_menu(); // Display menu and get user choice
    if (choice == "A") {
        string ciphered = valid_characters();
        string ciphered_2 = affine_cipher(ciphered);
        cout << "Ciphered string: " << ciphered_2;
        cout<<endl<<endl;
        string choice_ctn;
        cout<<"If you would like to continue, enter A"<<endl;
        cout<<"If you don't want to continue, enter B"<<endl;
        cin >> choice_ctn;
        while (true) {
            if (choice_ctn == "A") main();
            else if (choice_ctn == "B"){
                cout<<"Thank you for using this program"<<endl;
                exit(0);
            }
            else {
                cout << "Please enter a valid choice: " << endl;
                cin >> choice_ctn;
            }
        }
    }
    if (choice == "B") {
        string deciphered = valid_characters();
        string deciphered_2 = affine_decipher(deciphered);
        cout << "Deciphered string: " << deciphered_2;
        cout<<endl<<endl;
        string choice_ctn;
        cout<<"If you would like to continue, enter A"<<endl;
        cout<<"If you don't want to continue, enter B"<<endl;
        cin >> choice_ctn;
        while (true) {
            if (choice_ctn == "A") main();
            else if (choice_ctn == "B"){
                cout<<"Thank you for using this program"<<endl;
                exit(0);
            }
            else {
                cout << "Please enter a valid choice: " << endl;
                cin >> choice_ctn;
            }
        }
    }
    else if (choice == "C") {
        cout << "Thank you for using this program\n";
        exit(0);
    }
}
bool validate_characters(string input) {
    for (char chr : input) { // Iterate through each character in the input string
        if (!(toupper(chr) >= 'A' && toupper(chr) <= 'Z' || chr == ' ')) { // Check if character is a letter or space
            return false; // this will be happened if chr isn't valid
        }
    }
    return true; // this will be happened if all chr on input is valid
}
string valid_characters() {
    string input ="";
    do {
        cout << "Enter a string: ";
        getline(cin, input); // make user input string that he wants to cipher or decipher
        while(input==""){ // check if input is empty or not
            cout<<"please enter string: "<<endl;
            getline(cin, input); // make user input string that he wants to cipher or decipher
        }
        if (!validate_characters(input)) { // check if user inputs valid characters or not
            cout << "Invalid input. Please enter a string containing only letters between A&Z or a&z and spaces.\n";
        }
    } while (!validate_characters(input)); // Repeat until a valid input is provided
    return input;
}
string affine_menu() {
    string choice="";
    cout << "A: Cipher string\n" << "B: Decipher string\n"<< "C: Exit\n";
    getline(cin, choice); // make user inputs his choice
    while(choice==""){
        cout<<"please enter choice\n";
        cout << "A: Cipher string\n" << "B: Decipher string\n"<< "C: Exit\n";
        getline(cin, choice); // make user inputs his choice
    }
    string choice_2;
    for (int i = 0; i < choice.size(); i++) {
        choice_2 += toupper(choice[i]); // Convert user choice to uppercase
    }
    while (choice_2 != "A" && choice_2 != "B" && choice_2 != "C") { // iterate when user's input isn't A and B and C
        choice_2 = "";
        cout << "Invalid choice\n";
        cout << "A: Cipher string\n" << "B: Decipher string\n" << "C: Exit\n";
        getline(cin, choice); // make user input his choice again
        while(choice==""){
            cout<<"please enter choice\n";
            cout << "A: Cipher string\n" << "B: Decipher string\n"<< "C: Exit\n";
            getline(cin, choice); // make user inputs his choice
        }
        for (int i = 0; i < choice.size(); i++) {
            choice_2 += toupper(choice[i]); // Convert user choice to uppercase
        }
    }
    return choice_2; // return correct choice
}
string affine_cipher(string s) {
    string after;
    int choice;
    long long a,b,c;
    a = 5;
    b = 8;
    c = 21;
    for (char c : s) {
        if (c == ' ') {
            after += ' '; // make concatenation between space and string after
            continue;
        }
        int x = toupper(c)-65;
        x*=a;
        x+=b;
        x%=26;
        x+=65;
        char encryptedChar = char(x);
        after += toupper(encryptedChar); // make concatenation between string after and char encrypted char
    }
    return after; //save string after to use it again
}
string affine_decipher(string s) {
    string after;
    int choice;
    long long a,b,c;
    a = 5;
    b = 8;
    c = 21;
    char decryptedChar;
    for (char h : s) {
        if (h == ' ') {
            after += ' '; // make concatenation between space and string after
            continue;
        }
        long long x = toupper(h) - 65;
        x = ((x - b) * c); // Apply decryption formula
        x = ((x%26)+26)%26;
        decryptedChar = char(x + 97);
        after += toupper(decryptedChar);
    }
    return after; //save string after to use it again

}
void morse_main(){
    cout<<"Welcome to Morse cipher"<<endl;
    cin.ignore();
    string choice = morse_menu();
    if(choice=="A"){
        string s = morse_input_cipher();
        string s_2 = morse_cipher(s);
        cout<<s_2;
        cout<<endl<<endl;
        string choice_ctn;
        cout<<"If you would like to continue, enter A"<<endl;
        cout<<"If you don't want to continue, enter B"<<endl;
        cin >> choice_ctn;
        while (true) {
            if (choice_ctn == "A") main();
            else if (choice_ctn == "B"){
                cout<<"Thank you for using this program"<<endl;
                exit(0);
            }
            else {
                cout << "Please enter a valid choice: " << endl;
                cin >> choice_ctn;
            }
        }
    }
    else if(choice=="B"){
        string s = morse_input_decipher();
        string s_2 = morse_decipher(s);
        cout<<s_2;
        cout<<endl<<endl;
        string choice_ctn;
        cout<<"If you would like to continue, enter A"<<endl;
        cout<<"If you don't want to continue, enter B"<<endl;
        cin >> choice_ctn;
        while (true) {
            if (choice_ctn == "A") main();
            else if (choice_ctn == "B"){
                cout<<"Thank you for using this program"<<endl;
                exit(0);
            }
            else {
                cout << "Please enter a valid choice: " << endl;
                cin >> choice_ctn;
            }
        }
    }
    else if(choice=="C"){
        cout<<"Thank you for using this program\n";
        exit(0);
    }
}
string morse_input_cipher() {
    string s;
    bool validInput = false;
    while (!validInput) { // iterate when value of validInput is true
        cout << "Enter a string: ";
        getline(cin, s);
        while(s==""){
            cout << "please Enter a string: ";
            getline(cin, s);
        }
        bool valid = true;
        for (char c : s) {
            if (!isalpha(c) && c != ' ' && !isdigit(c)) { // check if c is characters or digits
                valid = false;
                break;
            }
        }
        if (!valid) { // check if value of valid is false or not
            cout << "Enter a valid string\n";
        }
        else { // if string that user input is valid make validInput equals to true
            validInput = true;
        }
    }
    return s;
}
string morse_input_decipher() {
    string s ="";
    bool validInput = false;
    while (!validInput) { // iterate when value of validInput is true
        cout << "Enter a string as .&-: ";
        getline(cin, s);
        while(s==""){
            cout << "please Enter a string as .&-: ";
            getline(cin, s);
        }
        bool valid = true;
        bool spaces = false;
        for (char c : s) {
            if (c != '-' && c != ' ' && c != '.') { // Check if c equals to - or . or space
                valid = false;
                break;
            }
            if(isspace(c)){
                spaces = true;
            }
        }
        if (!valid) { // check if value of valid is false or not
            cout << "Enter a valid string with spaces between each letter and word\n";
        }
        else if(!spaces){
            cout << "Enter a valid string with spaces between each letter and word\n";
        }
        else { // if string that user input is valid make validInput equals to true
            validInput = true;
        }
    }
    return s;
}

string morse_cipher(string cipher){
    string s_2="";
    for(int i = 0;i<cipher.size();i++){ // iterate on indexes of string cipher
        if(cipher[i]==' '){
            s_2+="  ";
        }
        else if(cipher[i]=='a'||cipher[i]=='A'){
            if(i==0){
                s_2+=".-";
            }
            else{
                s_2+=" .-";
            }
        }
        else if(cipher[i]=='b'||cipher[i]=='B'){
            if(i==0){
                s_2+="-...";
            }
            else{
                s_2+=" -...";
            }
        }
        else if(cipher[i]=='c'||cipher[i]=='C'){
            if(i==0){
                s_2+="-.-.";
            }
            else{
                s_2+=" -.-.";
            }
        }
        else if(cipher[i]=='d'||cipher[i]=='D'){
            if(i==0){
                s_2+="-..";
            }
            else{
                s_2+=" -..";
            }
        }
        else if(cipher[i]=='e'||cipher[i]=='E'){
            if(i==0){
                s_2+=".";
            }
            else{
                s_2+=" .";
            }
        }
        else if(cipher[i]=='f'||cipher[i]=='F'){
            if(i==0){
                s_2+="..-.";
            }
            else{
                s_2+=" ..-.";
            }
        }
        else if(cipher[i]=='g'||cipher[i]=='G'){
            if(i==0){
                s_2+="--.";
            }
            s_2+=" --.";
        }
        else if(cipher[i]=='h'||cipher[i]=='H'){
            if(i==0){
                s_2+="....";
            }
            else{
                s_2+=" ....";
            }
        }
        else if(cipher[i]=='i'||cipher[i]=='I'){
            if(i==0){
                s_2+="..";
            }
            else{
                s_2+=" ..";
            }
        }
        else if(cipher[i]=='j'||cipher[i]=='J'){
            if(i==0){
                s_2+=".---";
            }
            else{
                s_2+=" .---";
            }
        }
        else if(cipher[i]=='k'||cipher[i]=='K'){
            if(i==0){
                s_2+="-.-";
            }
            else{
                s_2+=" -.-";
            }
        }
        else if(cipher[i]=='l'||cipher[i]=='L'){
            if(i==0){
                s_2+=".-..";
            }
            else{
                s_2+=" .-..";
            }
        }
        else if(cipher[i]=='m'||cipher[i]=='M'){
            if(i==0){
                s_2+="--";
            }
            else{
                s_2+=" --";
            }
        }
        else if(cipher[i]=='n'||cipher[i]=='N'){
            if(i==0){
                s_2+="-.";
            }
            else{
                s_2+=" -.";
            }
        }
        else if(cipher[i]=='o'||cipher[i]=='O'){
            if(i==0){
                s_2+="---";
            }
            else{
                s_2+=" ---";
            }
        }
        else if(cipher[i]=='p'||cipher[i]=='P'){
            if(i==0){
                s_2+=".--.";
            }\
            else{
                s_2+=" .--.";
            }
        }
        else if(cipher[i]=='q'||cipher[i]=='Q'){
            if(i==0){
                s_2+="--.-";
            }
            else{
                s_2+=" --.-";
            }
        }
        else if(cipher[i]=='r'||cipher[i]=='R'){
            if(i==0){
                s_2+=".-.";
            }
            else{
                s_2+=" .-.";
            }
        }
        else if(cipher[i]=='s'||cipher[i]=='S'){
            if(i==0){
                s_2+="...";
            }
            else{
                s_2+=" ...";
            }
        }
        else if(cipher[i]=='t'||cipher[i]=='T'){
            if(i==0){
                s_2+="-";
            }
            else{
                s_2+=" -";
            }
        }
        else if(cipher[i]=='u'||cipher[i]=='U'){
            if(i==0){
                s_2+="..-";
            }
            else{
                s_2+=" ..-";
            }
        }
        else if(cipher[i]=='l'||cipher[i]=='L'){
            if(i==0){
                s_2+=" .-..";
            }
            else{
                s_2+=" .-..";
            }
        }
        else if(cipher[i]=='v'||cipher[i]=='V'){
            if(i==0){
                s_2+="...-";
            }
            else{
                s_2+=" ...-";
            }
        }
        else if(cipher[i]=='w'||cipher[i]=='W'){
            if(i==0){
                s_2+=".--";
            }
            else{
                s_2+=" .--";
            }
        }
        else if(cipher[i]=='x'||cipher[i]=='X'){
            if(i==0){
                s_2+="-..-";
            }
            else{
                s_2+=" -..-";
            }
        }
        else if(cipher[i]=='y'||cipher[i]=='Y'){
            if(i==0){
                s_2+="-.--";
            }
            else{
                s_2+=" -.--";
            }
        }
        else if(cipher[i]=='z'||cipher[i]=='Z'){
            if(i==0){
                s_2+="--..";
            }
            else{
                s_2+=" --..";
            }
        }
        else if(cipher[i]=='1'){
            if(i==0){
                s_2+=".----";
            }
            else{
                s_2+=" .----";
            }
        }
        else if(cipher[i]=='2'){
            if(i==0){
                s_2+="..---";
            }
            else{
                s_2+=" ..---";
            }
        }
        else if(cipher[i]=='3'){
            if(i==0){
                s_2+="...--";
            }
            else{
                s_2+=" ...--";
            }
        }
        else if(cipher[i]=='4'){
            if(i==0){
                s_2+="....-";
            }
            else{
                s_2+=" ....-";
            }
        }
        else if(cipher[i]=='5'){
            if(i==0){
                s_2+=".....";
            }
            else{
                s_2+=" .....";
            }
        }
        else if(cipher[i]=='6'){
            if(i==0){
                s_2+="-....";
            }
            else{
                s_2+=" -....";
            }
        }
        else if(cipher[i]=='7'){
            if(i==0){
                s_2+="--...";
            }
            else{
                s_2+=" --...";
            }
        }
        else if(cipher[i]=='8'){
            if(i==0){
                s_2+="---..";
            }
            else{
                s_2+=" ---..";
            }
        }
        else if(cipher[i]=='9'){
            if(i==0){
                s_2+="----.";
            }
            else{
                s_2+=" ----.";
            }
        }
        else if(cipher[i]=='0'){
            if(i==0){
                s_2+="-----";
            }
            else{
                s_2+=" -----";
            }
        }
    }
    return s_2;
}
string morse_decipher(string cipher) {
    string s_2;
    string currentCharacter;
    for (char chr : cipher) { // iterate on indexes of string cipher
        if (chr == ' ') { // check if this chr is space or not
            if(currentCharacter == "   "){
                s_2 += ' ';
            }
            else if (currentCharacter == ".-"){
                s_2 += 'A';
            }
            else if (currentCharacter == "-..."){
                s_2 += 'B';
            }
            else if (currentCharacter == "-.-."){
                s_2 += 'C';
            }
            else if (currentCharacter == "-.."){
                s_2 += 'D';
            }
            else if (currentCharacter == "."){
                s_2 += 'E';
            }
            else if (currentCharacter == "..-."){
                s_2 += 'F';
            }
            else if (currentCharacter == "--."){
                s_2 += 'G';
            }
            else if (currentCharacter == "...."){
                s_2 += 'H';
            }
            else if (currentCharacter == ".."){
                s_2 += 'I';
            }
            else if (currentCharacter == ".---"){
                s_2 += 'J';
            }
            else if (currentCharacter == "-.-"){
                s_2 += 'K';
            }
            else if (currentCharacter == ".-.."){
                s_2 += 'L';
            }
            else if (currentCharacter == "--"){
                s_2 += 'M';
            }
            else if (currentCharacter == "-."){
                s_2 += 'N';
            }
            else if (currentCharacter == "---"){
                s_2 += 'O';
            }
            else if (currentCharacter == ".--."){
                s_2 += 'P';
            }
            else if (currentCharacter == "--.-"){
                s_2 += 'Q';
            }
            else if (currentCharacter == ".-."){
                s_2 += 'R';
            }
            else if (currentCharacter == "..."){
                s_2 += 'S';
            }
            else if (currentCharacter == "-"){
                s_2 += 'T';
            }
            else if (currentCharacter == "..-"){
                s_2 += 'U';
            }
            else if (currentCharacter == "...-"){
                s_2 += 'V';
            }
            else if (currentCharacter == ".--"){
                s_2 += 'W';
            }
            else if (currentCharacter == "-..-"){
                s_2 += 'X';
            }
            else if (currentCharacter == "-.--"){
                s_2 += 'Y';
            }
            else if (currentCharacter == "--.."){
                s_2 += 'Z';
            }
            else if (currentCharacter == ".----"){
                s_2 += '1';
            }
            else if (currentCharacter == "..---"){
                s_2 += '2';
            }
            else if (currentCharacter == "...--"){
                s_2 += '3';
            }
            else if (currentCharacter == "....-"){
                s_2 += '4';
            }
            else if (currentCharacter == "....."){
                s_2 += '5';
            }
            else if (currentCharacter == "-...."){
                s_2 += '6';
            }
            else if (currentCharacter == "--..."){
                s_2 += '7';
            }
            else if (currentCharacter == "---.."){
                s_2 += '8';
            }
            else if (currentCharacter == "----."){
                s_2 += '9';
            }
            else if (currentCharacter == "-----"){
                s_2 += '0';
            }

            currentCharacter = "";
        }
        else {
            currentCharacter += chr; // make concatenation between currentCharacter and chr
        }
    }
    if (!currentCharacter.empty()) { // check if current character is empty or not
        if(currentCharacter == "   "){
            s_2 += ' ';
        }
        else if (currentCharacter == ".-"){
            s_2 += 'A';
        }
        else if (currentCharacter == "-..."){
            s_2 += 'B';
        }
        else if (currentCharacter == "-.-."){
            s_2 += 'C';
        }
        else if (currentCharacter == "-.."){
            s_2 += 'D';
        }
        else if (currentCharacter == "."){
            s_2 += 'E';
        }
        else if (currentCharacter == "..-."){
            s_2 += 'F';
        }
        else if (currentCharacter == "--."){
            s_2 += 'G';
        }
        else if (currentCharacter == "...."){
            s_2 += 'H';
        }
        else if (currentCharacter == ".."){
            s_2 += 'I';
        }
        else if (currentCharacter == ".---"){
            s_2 += 'J';
        }
        else if (currentCharacter == "-.-"){
            s_2 += 'K';
        }
        else if (currentCharacter == ".-.."){
            s_2 += 'L';
        }
        else if (currentCharacter == "--"){
            s_2 += 'M';
        }
        else if (currentCharacter == "-."){
            s_2 += 'N';
        }
        else if (currentCharacter == "---"){
            s_2 += 'O';
        }
        else if (currentCharacter == ".--."){
            s_2 += 'P';
        }
        else if (currentCharacter == "--.-"){
            s_2 += 'Q';
        }
        else if (currentCharacter == ".-."){
            s_2 += 'R';
        }
        else if (currentCharacter == "..."){
            s_2 += 'S';
        }
        else if (currentCharacter == "-"){
            s_2 += 'T';
        }
        else if (currentCharacter == "..-"){
            s_2 += 'U';
        }
        else if (currentCharacter == "...-"){
            s_2 += 'V';
        }
        else if (currentCharacter == ".--"){
            s_2 += 'W';
        }
        else if (currentCharacter == "-..-"){
            s_2 += 'X';
        }
        else if (currentCharacter == "-.--"){
            s_2 += 'Y';
        }
        else if (currentCharacter == "--.."){
            s_2 += 'Z';
        }
        else if (currentCharacter == ".----"){
            s_2 += '1';
        }
        else if (currentCharacter == "..---"){
            s_2 += '2';
        }
        else if (currentCharacter == "...--"){
            s_2 += '3';
        }
        else if (currentCharacter == "....-"){
            s_2 += '4';
        }
        else if (currentCharacter == "....."){
            s_2 += '5';
        }
        else if (currentCharacter == "-...."){
            s_2 += '6';
        }
        else if (currentCharacter == "--..."){
            s_2 += '7';
        }
        else if (currentCharacter == "---.."){
            s_2 += '8';
        }
        else if (currentCharacter == "----."){
            s_2 += '9';
        }
        else if (currentCharacter == "-----"){
            s_2 += '0';
        }
        currentCharacter = "";
    }
    return s_2;
}
string morse_menu() {
    string choice;
    cout << "A: Cipher string\n" << "B: Decipher string\n"<< "C: Exit\n";
    getline(cin, choice); // make user inputs his choice
    string choice_2;
    for (int i = 0; i < choice.size(); i++) {
        choice_2 += toupper(choice[i]); // Convert user choice to uppercase
    }
    while (choice_2 != "A" && choice_2 != "B" && choice_2 != "C") { // iterate when user's input isn't A and B and C
        choice_2 = "";
        cout << "Invalid choice\n";
        cout << "A: Cipher string\n" << "B: Decipher string\n" << "C: Exit\n";
        getline(cin, choice); // make user input his choice again
        for (int i = 0; i < choice.size(); i++) {
            choice_2 += toupper(choice[i]); // Convert user choice to uppercase
        }
    }
    return choice_2; // return correct choice
}
