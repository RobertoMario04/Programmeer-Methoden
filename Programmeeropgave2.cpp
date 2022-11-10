// Robert Salden, Thomas Verwaal
// Opgave 2 Pincode
// Compiler: g++, versie 9.3.0
// Dit programma geeft de mogelijkheid om een .txt file te coderen of
// decoderen, hiernaast is het ook mogelijk om een pincode te 'kraken'
// en herkent het programma lychrel getallen.

#include <iostream>
#include <fstream>
#include <climits>

using namespace std;

void Infoblokje ( ) {
    cout << "Infoblokje." << endl;
}

bool is_cijfer (char kar, int & new_pin){
    return (kar > '0' && kar <= '9') || (kar == '0' && new_pin != 0);
}

int reverse_int (int x){
    int reversed_number = 0;
    int remainder = 0;

    reversed_number = remainder;
    while (x != 0){
        remainder = x % 10;
        reversed_number = reversed_number * 10 + remainder;
        x /= 10;
    }
    return reversed_number;
}

void lychrel (int number ){
    int reversed_number;
    int iteraties;

    cout << "Mogelijk lychrel getal: " << number << endl;
    while (number < INT_MAX){
        iteraties++;
        reversed_number = reverse_int (number);
        if (number >= INT_MAX - reversed_number){
            number = INT_MAX;
        }
        else{
            number += reversed_number;
        }
        if (number == reverse_int (number)){
            cout << number << " is een lychrel getal na " << iteraties; 
            cout << " iteraties" << endl;
            number = INT_MAX;
        }
    }
    cout << "Aantal iteraties:" << iteraties << endl;
}

void pincode (int & new_pin, int & cijfer1, int & cijfer2,
int & cijfer3, int & cijfer4){
    cijfer4 = new_pin % 10;
    new_pin = new_pin / 10;
    cijfer3 = new_pin % 10;
    new_pin = new_pin / 10;
    cijfer2 = new_pin % 10;
    new_pin = new_pin / 10;
    cijfer1 = new_pin % 10;
}

void volgendeletter (char & kar, int & cijfer1, int & cijfer2, 
int & cijfer3, int & cijfer4, int & n, char & cd){
    int optel;
    if ( n % 4 == 0){
        optel = cijfer1;
    }
    if ( n % 4 == 1){
        optel = cijfer2;
    }
    if ( n % 4 == 2){
        optel = cijfer3;
    }
    if ( n % 4 == 3){
        optel = cijfer4;
    }
    n++;
    if (cd == 'c'){
        if (kar + optel > '~'){
            kar = kar % 95;
        }
        kar += optel;
    }
    else{
        if (kar - optel < ' '){
            kar = kar + 95;
        }
        kar -= optel;
    }
}


void coderen (ifstream & invoer, ofstream & uitvoer, int & pin, 
char & cd, bool unknown_pin, int & the_counter){
    int cijfer1;
    int cijfer2;
    int cijfer3;
    int cijfer4;
    int kar_counter = 0;
    int new_line_counter = 0;
    char kar;
    char prev_kar1 = '0';
    char prev_kar2 = '0';
    int n = 0;
    int new_pin = 0;

    pincode (pin, cijfer1, cijfer2, cijfer3, cijfer4);

    kar = invoer.get();
    while ( !invoer.eof ()){
        kar_counter++;
        if (cd == 'c'){
            if (is_cijfer(kar, new_pin)){
                new_pin = new_pin * 10 + kar - '0';
                volgendeletter (kar, cijfer1, cijfer2, cijfer3, 
                cijfer4, n, cd);
            }
            else if (new_pin != 0 && new_pin <= 9999){
                if (kar != '\n' && kar != '\r' && kar != '\t'){
                    volgendeletter (kar, cijfer1, cijfer2, cijfer3, 
                    cijfer4, n, cd);
                }
                pincode (new_pin, cijfer1, cijfer2, cijfer3, cijfer4);
                new_pin = 0;
                n = 0;
            }
            else if (new_pin > 9999){
                new_pin = 0;
                volgendeletter (kar, cijfer1, cijfer2, cijfer3, cijfer4, 
                n, cd);
            }
            else if (kar != '\n' && kar != '\r' && kar != '\t'){
                volgendeletter (kar, cijfer1, cijfer2, cijfer3, cijfer4, 
                n, cd);
            }
        }


        if (cd == 'd'){
            if (kar != '\n' && kar != '\r' && kar != '\t'){
                volgendeletter (kar, cijfer1, cijfer2, cijfer3, cijfer4, 
                n, cd);
            }
            else if (kar == '\n'){
                n = 0;
            }
            if (is_cijfer (kar, new_pin)){
                new_pin = new_pin * 10 + kar - '0';
            }
            else if (new_pin != 0 && new_pin <= 9999){
                //hier lychrel functie
                pincode (new_pin, cijfer1, cijfer2, cijfer3, cijfer4);
                new_pin = 0;
                n = 0;

            }
            else if (new_pin > 9999){
                new_pin = 0;
            }
        }

        if (kar == '\n'){
            new_line_counter++;
            n = 0;
        }
        if ( ! unknown_pin){
            uitvoer.put (kar);
        }
        else if (unknown_pin){
            if ((prev_kar2 == 't' || prev_kar2 == 'T') && (prev_kar1 == 'h' ||
            prev_kar1 == 'H') && (kar == 'e' || kar == 'E')){
                the_counter++;
            }
            prev_kar2 = prev_kar1;
            prev_kar1 = kar;
        }
        kar = invoer.get();
    }
    if ( ! unknown_pin){
        cout << "Totaal aantal karakters: " << kar_counter << endl;
        cout << " Totaal aantal newline's: ";
        cout << new_line_counter << endl;
    }
}


int main (){
    int pin;
    int test_pin = 1;
    char cd;
    bool unknown_pin;
    int the_counter = 0;
    int old_the_counter = 0;
    int i;
    string org_file;
    string doel_file;

    ifstream invoer;
    ofstream uitvoer;
    //check of file niet leeg is???.
    cout << "Voer in c voor coderen of d voor decoderen : " << endl;
    cin >> cd;
    cout << "Wat is de naam van de originele file?" << endl;
    cin >> org_file;

    if (invoer.fail ()){
        cout << "File niet geopend" << endl;
        return 1;
    }
    cout << "En van de doel file?"  << endl;
    cin >> doel_file;
    uitvoer.open (doel_file);

    if (cd == 'c'){
        cout << "Geef een pincode van vier cijfers,";
        cout << "bijvoorbeeld: 1234" << endl;
        cin >> pin;
        if (pin > 9999 || pin < -1){
            return 1;
        }
    }
    if (cd == 'd'){
        cout << "Geef de pincode, bijvoorbeeld: 1234. Als u de pincode ";
        cout << "niet weet voer dan -1 in" << endl;
        cin >> pin;
        if (pin > 9999 || pin < -1){
            return 1;
        }
        if (pin == -1){
            unknown_pin = true;
            pin = 0;
            i = 1;
            while ( i < 10000){
                invoer.open (org_file);
                test_pin = i;
                coderen (invoer, uitvoer, test_pin, cd, unknown_pin, 
                the_counter);
                if (the_counter > old_the_counter){
                    pin = i;
                    old_the_counter = the_counter;
                }
                the_counter = 0;
                invoer.close();
                i++;
            }
            cout << "De pincode is: " << pin << endl;
            if (pin != -1){
                unknown_pin = false;
            }
        }
    }
    invoer.open (org_file);
    coderen (invoer, uitvoer, pin, cd, unknown_pin, the_counter);
    invoer.close();
    uitvoer.close();
    return 0;
}
