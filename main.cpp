#include <iostream>
#include <string>
using namespace std;

// ---------------Helper Functions ---------------

bool isBinary(string s) {
    for (char c : s) {
        if (c != '0' && c != '1') return false;
    }
    return true;
}

bool isOctal(string s) {
    for (char c : s) {
        if (c < '0' || c > '7') return false;
    }
    return true;
}

bool isHex(string s) {
    for (char c : s) {
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
            return false;
        }
    }
    return true;
}

// ---------------Conversion Functions ------------

// 1. Decimal to Binary
string decToBin(int num) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        result = char('0' + (num % 2)) + result;
        num = num / 2;
    }
    return result;
}

// 2. Decimal to Octal
string decToOct(int num) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        result = char('0' + (num % 8)) + result;
        num = num / 8;
    }
    return result;
}

// 3. Decimal to Hexadecimal
string decToHex(int num) {
    if (num == 0) return "0";
    string result = "";
    while (num > 0) {
        int rem = num % 16;
        if (rem < 10)
            result = char('0' + rem) + result;
        else
            result = char('A' + rem - 10) + result;
        num = num / 16;
    }
    return result;
}

// 4. Binary to Decimal
int binToDec(string bin) {
    int result = 0;
    int power = 1;
    for (int i = bin.length() - 1; i >= 0; i--) {
        if (bin[i] == '1') {
            result = result + power;
        }
        power *= 2;
    }
    return result;
}

// 5. Binary to Octal
string binToOct(string bin) {
    int dec = binToDec(bin);
    return decToOct(dec);
}

// 6. Binary to Hexadecimal
string binToHex(string bin) {
    int dec = binToDec(bin);
    return decToHex(dec);
}

// 7. Octal to Decimal
int octToDec(string oct) {
    int result = 0;
    int power = 1; // 8^0
    for (int i = oct.length() - 1; i >= 0; i--) {
        result = result + (oct[i] - '0') * power;
        power *= 8;
    }
    return result;
}

// 8. Octal to Binary
string octToBin(string oct) {
    int dec = octToDec(oct);
    return decToBin(dec);
}

// 9. Octal to Hexadecimal
string octToHex(string oct) {
    int dec = octToDec(oct);
    return decToHex(dec);
}

// 10. Hexadecimal to Decimal
int hexToDec(string hex) {
    int result = 0;
    int power = 1; // 16^0
    for (int i = hex.length() - 1; i >= 0; i--) {
        int digit;
        if (hex[i] >= '0' && hex[i] <= '9')
            digit = hex[i] - '0';
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            digit = hex[i] - 'A' + 10;
        else
            digit = hex[i] - 'a' + 10;
        result = result + digit * power;
        power *= 16;
    }
    return result;
}

// 11. Hexadecimal to Binary
string hexToBin(string hex) {
    int dec = hexToDec(hex);
    return decToBin(dec);
}

// 12. Hexadecimal to Octal
string hexToOct(string hex) {
    int dec = hexToDec(hex);
    return decToOct(dec);
}

// --------------Menu Display -------------

void showMenu() {
    cout << "\n------------------------" << endl;
    cout << "     NUMBER SYSTEM CONVERTER" << endl;
    cout << "-------------------------" << endl;
    cout << " 1. Decimal    to Binary" << endl;
    cout << " 2. Decimal    to Octal" << endl;
    cout << " 3. Decimal    to Hexadecimal" << endl;
    cout << " 4. Binary     to Decimal" << endl;
    cout << " 5. Binary     to Octal" << endl;
    cout << " 6. Binary     to Hexadecimal" << endl;
    cout << " 7. Octal      to Decimal" << endl;
    cout << " 8. Octal      to Binary" << endl;
    cout << " 9. Octal      to Hexadecimal" << endl;
    cout << "10. Hexadecimal to Decimal" << endl;
    cout << "11. Hexadecimal to Binary" << endl;
    cout << "12. Hexadecimal to Octal" << endl;
    cout << " 0. Exit" << endl;
    cout << "-----------------------" << endl;
    cout << "Enter your choice: ";
}

// ---------------- Main Function ---------------

int main() {
    int choice;       
    string inputStr;  
    int inputNum;     

    cout << "Welcome to Number System Converter!" << endl;

    // Loop until user chooses to exit (0)
    while (true) {
        showMenu();
        cin >> choice;

        // Exit the program
        if (choice == 0) {
            cout << "\nThank you for using Number System Converter. Goodbye!" << endl;
            break;
        }

        // Check if choice is valid
        if (choice < 1 || choice > 12) {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }

        if (choice >= 1 && choice <= 3) {
            // Decimal input
            cout << "Enter a Decimal number: ";
            cin >> inputNum;
        }
        else if (choice >= 4 && choice <= 6) {
            // Binary input
            cout << "Enter a Binary number: ";
            cin >> inputStr;
            if (!isBinary(inputStr)) {
                cout << "Error: Invalid Binary number!" << endl;
                continue;
            }
        }
        else if (choice >= 7 && choice <= 9) {
            // Octal input
            cout << "Enter an Octal number: ";
            cin >> inputStr;
            if (!isOctal(inputStr)) {
                cout << "Error: Invalid Octal number!" << endl;
                continue;
            }
        }
        else {
            // Hexadecimal input
            cout << "Enter a Hexadecimal number: ";
            cin >> inputStr;
            if (!isHex(inputStr)) {
                cout << "Error: Invalid Hexadecimal number!" << endl;
                continue;
            }
        }

        cout << "\n--- Result ---" << endl;

        switch (choice) {
            case 1:
                cout << "Decimal: " << inputNum << " to Binary: " << decToBin(inputNum) << endl;
                break;
            case 2:
                cout << "Decimal: " << inputNum << " to Octal: " << decToOct(inputNum) << endl;
                break;
            case 3:
                cout << "Decimal: " << inputNum << " to Hexadecimal: " << decToHex(inputNum) << endl;
                break;
            case 4:
                cout << "Binary: " << inputStr << " to Decimal: " << binToDec(inputStr) << endl;
                break;
            case 5:
                cout << "Binary: " << inputStr << " to Octal: " << binToOct(inputStr) << endl;
                break;
            case 6:
                cout << "Binary: " << inputStr << " to Hexadecimal: " << binToHex(inputStr) << endl;
                break;
            case 7:
                cout << "Octal: " << inputStr << " to Decimal: " << octToDec(inputStr) << endl;
                break;
            case 8:
                cout << "Octal: " << inputStr << " to Binary: " << octToBin(inputStr) << endl;
                break;
            case 9:
                cout << "Octal: " << inputStr << " to Hexadecimal: " << octToHex(inputStr) << endl;
                break;
            case 10:
                cout << "Hexadecimal: " << inputStr << " to Decimal: " << hexToDec(inputStr) << endl;
                break;
            case 11:
                cout << "Hexadecimal: " << inputStr << " to Binary: " << hexToBin(inputStr) << endl;
                break;
            case 12:
                cout << "Hexadecimal: " << inputStr << " to Octal: " << hexToOct(inputStr) << endl;
                break;
        }
    }

    return 0;
}
