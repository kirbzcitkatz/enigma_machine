//ENIGMA M3 (Kriegsmarine)
//https://www.cryptomuseum.com/crypto/enigma/wiring.htm
#include <iostream>
#include <vector>

using namespace std;

char alph[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char rotor1[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'L' };
char rotor2[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
char rotor3[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
char refl[26] = {'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T'};


int rdial_1;
int rdial_2;
int rdial_3;
//vars for the rotors (dial)

vector<char> swap_1;
vector<char> swap_2;
char char_buff;
int int_buff;
//plugboard swapping vars

char mb;
//main buffer

int fd_index(char in, char arr[26]) {
    for (int i = 0; i < 26; i++) {
        if (arr[i] == in) {
            return i;
        }
    }
};
//finds the index of a char from a given array

int control_range(int i) {
    if (i > 25) {
        i = i - 26;
    }
    else if (i < 0) {
        i = i + 26;
    }
    return i;
};

int main() {

    cout << "Enter the number for Dial 1: ";
    cin >> rdial_1;
    rdial_1 = rdial_1 - 1; //decrement is needed as the original dials would be 1-26
                           //and I need to make this compatible with a given array
    cout << "Enter the number for Dial 2: ";
    cin >> rdial_2;
    rdial_2 = rdial_2 - 1;

    cout << "Enter the number for Dial 3: ";
    cin >> rdial_3;
    rdial_3 = rdial_3 - 1;


    while (true) {
        cout << "\n\nswitch: ";
        cin >> char_buff;

        if (char_buff == '#') {
            break; // '#' is the signal for the end of setting up
        }
        else {
            swap_1.push_back(char_buff);
            cout << "with: ";
            cin >> char_buff;
            swap_2.push_back(char_buff);
        }
    }

    int limit = swap_1.size();
    //mainloop
    while (true) {
        cout << "input: ";
        cin >> mb;
        mb = toupper(mb);
        for (int i = 0; i < limit; i++) {
            if (mb == swap_1[i]) {
                mb = swap_2[i];
                break;
            }
            else if (mb == swap_2[i]) {
                mb = swap_1[i];
                break;
            }//if this letter is connected to the plugboard
             //then it will be swapped with corrisponding letter
        }

        
        mb = rotor1[control_range(fd_index(mb, alph) + rdial_1)];
        mb = rotor2[control_range(fd_index(mb, alph) + rdial_2)];
        mb = rotor3[control_range(fd_index(mb, alph) + rdial_3)];       
        mb = refl[fd_index(mb, alph)];       
        mb = alph[control_range(fd_index(mb, rotor3) - rdial_3)];
        mb = alph[control_range(fd_index(mb, rotor2) - rdial_2)];
        mb = alph[control_range(fd_index(mb, rotor1) - rdial_1)]; //bunch of bull$&!+ that took way to long
        
        for (int i = 0; i < limit; i++) {
            if (mb == swap_1[i]) {
                mb = swap_2[i];
                break;
            }
            else if (mb == swap_2[i]) {
                mb = swap_1[i];
                break;
            }
        }


        cout << mb << "\n";

        rdial_1++;

        rdial_1 > 25 ? rdial_1 = 0 && rdial_2++ : true;
        rdial_2 > 25 ? rdial_2 = 0 && rdial_3++ : true;
        rdial_3 > 25 ? rdial_3 = 0 : true;
    }   //rotate dials

    return 0;
}
