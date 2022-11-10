//
// Robert Salden Programmeeropgave 1 : Temperatuur,
// voor het vak Programmeermethoden. 26 september 2022
//
#include <iostream>
using namespace std;

const int huidigeJaar = 2022;
const int huidigeMaand = 9;
const int huidigeDag = 26;
const int gradenVerschil = 1;
const int gradenVerschilmin = -1;

int main () {

    int geboorteJaar;
    int geboorteMaand;
    int geboorteDag;
    bool schrikkelJaar;
    double leeftijdJaren;
    int leeftijdMaanden;
    int dagen;
    int schrikkelJaren;
    int berekendeDag;
    int resterendeMaanden;
    int februariDagen = 28;
    char dagGeboren;
    char dagGeboren2;
    char dagIng;
    char dagIng2;
    bool over30;
    int x;
    double antwoord1;
    double antwoord2;
    int antwoordIng1;
    int antwoordIng2;
    int antwoord1int;
    int antwoord2int;

    cout << "Geef als eerste je geboortejaar: " << endl;
    cin >> geboorteJaar;
    if ( (huidigeJaar - geboorteJaar) < 10 || (huidigeJaar - geboorteJaar > 101))  {
            cout << "Je valt helaas niet binnen de geaccepteerde leeftijden.";
            return 1;
    }//Het invoeren van het geboortejaar en gelijk checken voor ongeldige leeftijden.

    schrikkelJaar = ( geboorteJaar % 4 == 0 || geboorteJaar % 400 == 0);
    //Kijken of het ingevoerde jaar een schrikkeljaar is of niet.

    cout << "Geef nu je geboortemaand (1-12): " << endl;
    cin >> geboorteMaand;
    //Invoeren geboortemaand.

    if ( geboorteMaand > 12 || geboorteMaand < 1){
        cout << "Dit is geen geldige maand";
        return 2;
    }//Kijken of ingevoerde getal wel een maand is.

    if ( (huidigeJaar - geboorteJaar) == 101 && geboorteMaand < huidigeMaand) {
        cout << "Je valt helaas niet binnen de geaccepteerde leeftijden.";
        return 3;
    }//Met behulp van een berekening kijken of iemand wel binnen de leeftijden valt.

    if ( (huidigeJaar - geboorteJaar) == 10 && huidigeMaand < geboorteMaand){
        cout << "Je valt helaas niet binnen de geaccepteerde leeftijden";
        return 4;
    }//Wederom hetzelfde als hier boven.

    cout << "Geef nu je geboortedag (1-31): " << endl;
    cin >> geboorteDag;
    //Invoeren geboortedag.

    if ( geboorteDag > 31 || geboorteDag < 1) {
        cout << "Dit is geen geldige dag";
        return 5;
    }//Kijken of de geboortedag wel kan.

    if ( (geboorteMaand == 4 || geboorteMaand == 6 || geboorteMaand == 9
          || geboorteMaand == 11)
        && geboorteDag > 30){
        cout << "De opgegeven dag komt niet voor in de opgegeven maand.";
        return 7;
    }//Kijken of de geboortedag wel kan voorkomen in de opgegeven maand.

    if ( huidigeJaar - geboorteJaar == 10 && huidigeMaand == geboorteMaand
        && huidigeDag < geboorteDag) {
        cout << "Je valt helaas niet binnen de geaccepteerde leeftijden.";
        return 6;
    }//Laatste keer kijken of iemand wel binnen de leeftijden valt.

    if ( huidigeJaar - geboorteJaar == 101 && geboorteMaand == huidigeMaand
        && huidigeDag > geboorteDag){
        cout << "Je valt helaas niet binnen de geaccepteerde leeftijden.";
        return 6;
    }

    if (schrikkelJaar && geboorteMaand == 2 && geboorteDag > 29){
        cout << "De opgegeven dag komt niet voor in de opgegeven maand.";
        return 8;
    }

    if (schrikkelJaar == false && geboorteMaand == 2 && geboorteDag > 28){
        cout << "De opgegeven dag komt niet voor in de opgegeven maand.";
        return 9;

    }

    if ( geboorteMaand < huidigeMaand || (huidigeMaand == geboorteMaand
         && geboorteDag <= huidigeDag) ){
        leeftijdJaren = huidigeJaar - geboorteJaar;
        if ( geboorteMaand <= huidigeMaand && huidigeDag >= geboorteDag){
            leeftijdMaanden = leeftijdJaren * 12 + huidigeMaand - geboorteMaand;

        }
        else {
            leeftijdMaanden = leeftijdJaren * 12 + huidigeMaand - geboorteMaand - 1;
        }
    }

    if ( geboorteMaand > huidigeMaand || (geboorteMaand == huidigeMaand
         && geboorteDag > huidigeDag)){
        leeftijdJaren = huidigeJaar - geboorteJaar - 1;
        if (geboorteMaand > huidigeMaand && huidigeDag >= geboorteDag){
            leeftijdMaanden = leeftijdJaren * 12
            + (12 - (geboorteMaand - huidigeMaand));
        }
        else {
            leeftijdMaanden = leeftijdJaren * 12 +
            (12 - (geboorteMaand - huidigeMaand) - 1);
        }
    }

    resterendeMaanden = leeftijdMaanden % 12;

    if (geboorteMaand == huidigeMaand && geboorteDag == huidigeDag){
        cout << "Gefeliciteerd je bent vandaag jarig!" << endl;
    }

    if (geboorteDag == huidigeDag){
        cout << "Gefeliciteerd je bent vandaag maandig!" << endl;
    }

    cout << "Je leeftijd in jaren : " << leeftijdJaren << " Jaar en "
    << resterendeMaanden << " Maanden" << endl;
    cout << "Je leeftijd in maanden : " << leeftijdMaanden << endl;

    over30 = leeftijdJaren >= 30;

    schrikkelJaren = (geboorteJaar - 1901) / 4;
    dagen = ((geboorteJaar - 1901) - schrikkelJaren)
    * 365 + schrikkelJaren * 366;
    berekendeDag = dagen % 7;

    if (schrikkelJaar) {
        februariDagen = 29;
    }
    if (geboorteMaand == 1 || geboorteMaand == 2){
        dagen += geboorteDag + (31 * (geboorteMaand - 1));
        berekendeDag = dagen % 7;
    }
    if (geboorteMaand == 3 || geboorteMaand == 4){
        dagen += geboorteDag + februariDagen + (31 * (geboorteMaand - 2));
        berekendeDag = dagen % 7;
    }
    if  (geboorteMaand == 5 || geboorteMaand == 6){
        dagen += geboorteDag + februariDagen + (31 * (geboorteMaand - 3)) + 30;
        berekendeDag = dagen % 7;
    }
    if (geboorteMaand == 7 || geboorteMaand == 8 || geboorteMaand == 9){
        dagen += geboorteDag + februariDagen + (31 * (geboorteMaand - 4)) + 60;
        berekendeDag = dagen % 7;
    }
    if (geboorteMaand == 10 || geboorteMaand == 11){
        dagen += geboorteDag + februariDagen + (31 * (geboorteMaand - 5)) + 90;
        berekendeDag = dagen % 7;
    }
    if (geboorteMaand == 12){
        dagen += geboorteDag + februariDagen + (31 * (geboorteMaand - 6)) + 120;
        berekendeDag = dagen % 7;
    }
    if (berekendeDag == 0){
        dagGeboren = 'm';
    }
    if (berekendeDag == 1){
        dagGeboren = 'd';
        dagGeboren2 = 'i';
    }
    if (berekendeDag == 2){
        dagGeboren = 'w';
    }
    if (berekendeDag == 3){
        dagGeboren = 'd';
        dagGeboren2 = 'o';
    }
    if (berekendeDag == 4){
        dagGeboren = 'v';
    }
    if (berekendeDag == 5){
        dagGeboren = 'z';
        dagGeboren2 = 'a';
    }
    if (berekendeDag == 6){
        dagGeboren = 'z';
        dagGeboren2 = 'o';
    }

    cout << "Op welke dag van de week ben je geboren?";
    cout << " Voer de eerste letter van de dag in: " << endl;
    cin >> dagIng;

    if ((dagIng == 'd' || dagIng == 'z') && dagIng == dagGeboren){
        cout << "Wat is de tweede letter van de dag? : " << endl;
        cin >> dagIng2;
        if (dagIng2 != dagGeboren2){
            cout << "Dit klopt niet!" << endl;
            return 12;
        }
    }

    if (dagIng != dagGeboren){
        cout << "Dit klopt niet!" << endl;
        return 13;
    }
    cout << "Dit klopt!" << endl;

    srand (geboorteJaar + geboorteMaand + geboorteDag);
    x = rand() % 161 + (-40);
    antwoord1 = x * (9.0/5.0) + 32.0;
    antwoord2 = (x - 32) * (5.0/9.0);

    if (antwoord1 >= 0){
        antwoord1 += 0.5;
    }
    else {
        antwoord1 -= 0.5;
    }
    if (antwoord2 >= 0){
        antwoord2 += 0.5;
    }
    else {
        antwoord2 -= 0.5;
    }

    antwoord1int = antwoord1;
    antwoord2int = antwoord2;

    if (over30){
        cout << "U voldoet aan onze eisen, nu komt de eerste vraag: " << endl;
        cout << "Bereken het getal " << x;
        cout << " van celsius naar fahrenheit en andersom." << endl;
        cout << "Eerst van celsius naar fahrenheit, rond uw antwoord af : " << endl;
        cin >> antwoordIng1;
        cout << "Nu van fahrenheit naar celsius alstublieft : " << endl;
        cin >> antwoordIng2;

        if ((antwoordIng1 >= antwoord1int + gradenVerschilmin && antwoordIng1
            <= antwoord1int + gradenVerschil) || (antwoordIng2 >= antwoord2int
            + gradenVerschilmin && antwoordIng2 <= antwoord2int + gradenVerschil))
            cout << "Gefeliciteerd u bent toegelaten!";
            return 15;
    }
    else {
        cout << "Je voldoet aan onze eisen, nu komt de eerste vraag: " << endl;
        cout << "Bereken het getal " << x;
        cout << " van celsius naar fahrenheit en andersom." << endl;
        cout << "Eerst van celsius naar fahrenheit, rond je antwoord af : " << endl;
        cin >> antwoordIng1;
        cout << "Nu van fahrenheit naar celsius : " << endl;
        cin >> antwoordIng2;

        if ((antwoordIng1 >= antwoord1int + gradenVerschilmin && antwoordIng1
            <= antwoord1int + gradenVerschil) || (antwoordIng2 >= antwoord2int
            + gradenVerschilmin && antwoordIng2 <= antwoord2int + gradenVerschil))
            cout << "Gefeliciteerd je bent toegelaten!";
            return 16;
    }

return 0;
}
//main
