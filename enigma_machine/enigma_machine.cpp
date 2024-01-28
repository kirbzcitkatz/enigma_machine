//ENIGMA M3 (Kriegsmarine)
//https://www.cryptomuseum.com/crypto/enigma/wiring.htm
#include <iostream>
#include <string>
#include <vector>

using namespace std;

char alph[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
char rotor1[26] = { 'E', 'K', 'M', 'F', 'L', 'G', 'D', 'Q', 'V', 'Z', 'N', 'T', 'O', 'W', 'Y', 'H', 'X', 'U', 'S', 'P', 'A', 'I', 'B', 'R', 'C', 'L' };
char rotor2[26] = { 'A', 'J', 'D', 'K', 'S', 'I', 'R', 'U', 'X', 'B', 'L', 'H', 'W', 'T', 'M', 'C', 'Q', 'G', 'Z', 'N', 'P', 'Y', 'F', 'V', 'O', 'E' };
char rotor3[26] = { 'B', 'D', 'F', 'H', 'J', 'L', 'C', 'P', 'R', 'T', 'X', 'V', 'Z', 'N', 'Y', 'E', 'I', 'W', 'G', 'A', 'K', 'M', 'U', 'S', 'Q', 'O' };
char refl[26] = {'Y', 'R', 'U', 'H', 'Q', 'S', 'L', 'D', 'P', 'X', 'N', 'G', 'O', 'K', 'M', 'I', 'E', 'B', 'F', 'Z', 'C', 'W', 'V', 'J', 'A', 'T'};


int rDial_1;
int rDial_2;
int rDial_3;

int pDial_1;
int pDial_2;
int pDial_3;
//vars for the rotors (dial)

vector<char> swap_1;
vector<char> swap_2;
char char_buff;
int int_buff;
//plugboard swapping vars

int fd_index(char in, char arr[26]) {
    for (int i = 0; i < 26; i++) {
        if (arr[i] == in) {
            return i;
        }
    }
};

char mb;


//assigns index number for plugboard switching
int main() {

    cout << "Enter the number for Dial 1: ";
    cin >> rDial_1;
    rDial_1 = rDial_1 - 1;

    cout << "Enter the number for Dial 2: ";
    cin >> rDial_2;
    rDial_2 = rDial_2 - 1;

    cout << "Enter the number for Dial 3: ";
    cin >> rDial_3;
    rDial_3 = rDial_3 - 1;


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
    int r;
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
            }
        }

        /*
        mb = rotor#[control_0-25(alph.index[mb] + rdial_#)]

        mb = rotor#[control_0-25(alph.index[mb] + rdial_#)]

        mb = rotor#[control_0-25(alph.index[mb] + rdial_#)]
        
        mb = refl[rotor3.index[mb] 
        
        mb = alph[control_0-25(rotor#.index[mb] - rdial_#)]

        mb = alph[control_0-25(rotor#.index[mb] - rdial_#)]

        mb = alph[control_0-25(rotor#.index[mb] - rdial_#)]
        */


        


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

    }



    return 0;
}


