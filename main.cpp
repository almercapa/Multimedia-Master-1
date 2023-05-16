#include "GetValid.h"
#include <math.h>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>

// Add all other needed header files

using namespace std;
// Functions for calculating portion
void calculate(void);
int add(int num1,int num2);
int sub(int num1,int num2);
double divi(int num1,int num2);
int mult(int num1,int num2);
int expo(int num1,int num2);
double mod(int num1,int num2);
double sqrt(int num1);
// Functions for pizza portion
void pizzatime(void);
double findsubtotal(int a, double p);
double findtotal(double total);
// Functions for adventure portion
void adventure(void);
int diddy(int health);
int donkeykong(int health);


int main() {
  int mainmenu = 0;
  //MAIN MENU
  do {
    cout << "Main Menu:\n";
    cout << "1.) Calculator\n2.) Pizza\n3.) Adventure Game\n4.) End Program\n";
    cin >> mainmenu;
    if (mainmenu == 1) {
      calculate();
      mainmenu = 0;
    }
    if (mainmenu == 2) {
      pizzatime();
      mainmenu = 0;
    }
    if (mainmenu == 3) {
      adventure();
    }
    if (mainmenu == 4) {
      break;
    }
  } while((!(getValidInt(mainmenu)) || (mainmenu < 1) || (mainmenu >= 4)));//makes sure the user inputs a 
}
  

  void calculate(void) {
    //CALCULATOR CODE
    int op, num1,num2;
    string dummy, response;
    //variables for calculator part
    cout << "Would you like to make a calculation (Y/N)? ";
    cin >> response;
    while (response == "Y" || response == "y") {
      do{
        cout << "Which operation would you like to use?\n1.)Add\n2.)Subtract\n3.)Multiply\n4.)Divide\n5.)Exponent\n6.)Modulus\n7.)Root(EXTRA)\n";
        getline(cin,dummy);
      } while((!(getValidInt(op)) || (op < 1) || (op > 7)));
    
      //get both numbers
      do{
        cout << "Choose number one ";
      } while(!(getValidInt(num1)));

      do{
        cout << "Choose number two (does not apply if you choose #7): ";
      } while(!(getValidInt(num2)));
  
      //CALLING ALL OPERATION FUNCTIONS
      if(op==1){//addition
        cout << add(num1,num2) << endl;
      }
      else if(op==2){//subtraction
        cout << sub(num1,num2) << endl;
      }
      else if(op==3){//multiplication
        cout << mult(num1,num2) << endl;
      }
      else if(op==4){//division
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout << setprecision(2) << divi(num1,num2) << endl;
      }
      else if(op==5){//exponent
        cout << expo(num1,num2) << endl;
      }
      else if(op==6){//Modulus
        cout << mod(num1,num2) << endl;
      }
      else if(op==7){//EXTRA
        cout << sqrt(num1) << endl;
      }
      cout << "Would you like to make another calculation? ";
      cin >> response; 
    }
  }
  //ALL OPERATION FUNCTIONS
  int add(int num1,int num2){
    int total = num1 +num2;
    return total;
  }
  
  int sub(int num1,int num2){
    int total = num1-num2;
    return total;
  }

  double divi(int num1,int num2){
    double total = (num1 * 1.0)/num2;
    return total;
  }

  int mult(int num1,int num2){
    int total = num1*num2;
    return total;
  }
  
  int expo(int num1,int num2){
    int total = pow(num1,num2);
    return total;
  }

  double mod(int num1,int num2){
    double total = num1%num2;
    return total;
  }

  double sqrt(int num1){
    double total = sqrt(num1);
    return total;
  }

//START OF PIZZA TIME !!
  void pizzatime(void) {
    string order,dummy;
    //stores order as string 
    int pizza, amount;
    //declares the int variables.

    double piprice, taxRate, total;
    //double variables for the decimals

    cout << "\nWould you like to place an order (Y/N)? ";//ask if the user wants to place an order
    cin >> order;
    if (order == "Y" || order == "y") {
      getline(cin, dummy);
    }
    //stores order
  
    //while order is equal to "Y"
    while (order == "Y" || order == "y") {
      do {//the pizza menu
        cout << "What pizza type would you like to order:" << endl;
        cout << "1. Saddle of wild boar ($6.99)" << endl;
        cout << "2. Korean blueberries and ranch sauce ($5.99)" << endl;
        cout << "3. Mizza ($9.99)" << endl;
        cout << "4. Gluten free 🤮 ($0.01)" << endl;
        cout << "5. Banana curry ($15.99)" << endl;
      } while((!(getValidInt(pizza)) || (pizza < 1) || (pizza > 5)));
      if (pizza == 1) {
        piprice = 6.99;
        do {
         cout << "How many pizza slices would you like to order? ";
        } while((!(getValidInt(amount))));//how many slices they want to order
      }
      if (pizza == 2) {
        piprice = 5.99;
        do {
         cout << "How many pizza slices would you like to order? ";
        } while((!(getValidInt(amount))));//how many slices they want to order
      }
      if (pizza == 3) {
        piprice = 9.99;
        do {
         cout << "How many pizza slices would you like to order? ";
        } while((!(getValidInt(amount))));//how many slices they want to order
      }
      if (pizza == 4) {
        piprice = 0.01;
        do {
         cout << "How many pizza slices would you like to order? ";
        } while((!(getValidInt(amount))));//how many slices they want to order
      }
      if (pizza == 5) {
        piprice = 15.99;
        do {
         cout << "How many pizza slices would you like to order? ";
        } while((!(getValidInt(amount))));//how many slices they want to order
      }
      total = findsubtotal(amount, piprice);
      cout.setf(ios::fixed);
      cout.setf(ios::showpoint);
      cout << "\nSubtotal: $" << setprecision(2) << total << endl;
      total = findtotal(total);//prints the total
      cout << "Total: $" << setprecision(2) << total << endl;
      cout << "Would you like to place another order? ";
      cin >> order;
      if (order == "Y" || order == "y") {
        getline(cin, dummy);
      }
      else {
       cout << endl; 
      }
    }
  }
  double findsubtotal(int a, double p) {
    double stotal = a * p;
    return stotal;
  }
  double findtotal(double total) {
    double t = total + (total * 0.06625);
    return t;
  }

//START OF ADVENTURE !!
void adventure(void){
  string play, dummy;
  cout << "\nWould you like to start the adventure (Y/N)? ";//if they want to play the adventure game
  cin >> play;
  while (play == "Y" || play == "y") {
    int health = 100;
    health = diddy(health);
    if (health > 0) {
      health = 100;
      health = donkeykong(health);
      if (health > 0) {
        cout << "Would you like to play again (Y/N)? ";
        cin >> play;
      }
    }
    else {
      if (health <= 0) {
        getline(cin, dummy);
      }
      cout << "\nGAME OVER: Would you like to play again (Y/N)? ";
      cin >> play;//aks if they want to play again
    }
  }
}
//DIDDY KONG CODE

int diddy(int health){
  cout << 
"                ██████████████████████████\n"           
"            ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n "         
"            ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n"        
"          ██▒▒▒▒░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒░░░░██ \n"       
"      ██████▒▒░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░░░░░░░██\n"      
"    ██░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████\n"  
"    ██░░░░░░▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██░░░░██\n"
"    ██░░░░░░▒▒░░░░░░░░░░██░░░░░░░░██░░░░░░░░██░░░░██\n"
"      ████░░▒▒░░░░░░░░░░██░░░░░░░░██░░░░░░░░██████ \n" 
"          ██▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██\n "     
"  ████      ██▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░██\n"        
"██    ██      ██▒▒░░░░░░░░░░░░░░░░░░░░░░██\n"          
"██  ██      ██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n"        
"██          ██▒▒▒▒▒▒▒▒░░░░░░░░░░░░▒▒▒▒▒▒▒▒██\n "       
"  ████    ██▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒██\n"      
"      ██████▒▒▒▒▒▒▒▒░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒██\n"      
"          ██▒▒▒▒██▒▒░░░░░░░░░░░░░░░░▒▒██▒▒▒▒██\n"      
"            ██████▒▒▒▒░░░░░░░░░░░░▒▒▒▒██████\n"        
"                ██▒▒▒▒▒▒████████▒▒▒▒▒▒██\n"            
"                ██░░░░██        ██░░░░██\n"           
"                ██████            ██████\n";          
  int diddy= 100, CARTI = 70, YOUNGBOY = 25, scar= 99, heals = 3, choice, attack, random, dcount = 0;
  string dummy;//all the variables
  srand((unsigned) time(0));
  cout << "Diddy Kong heard you listening to Playboi Carti and attacks! Oh no!";//starting line
  while (diddy > 0 && health > 0) {
    random = (rand() % 75) + 1;
    do {
      if (dcount < 1) {
        getline(cin, dummy);
        dcount++;
      }
      cout << "\nWhat will you do? \n";
      cout << "1) Attack\n2) Impress\n3) Heal\n4) Offer\n";//possible options
    }  while((!(getValidInt(choice)) || (choice < 1) || (choice > 4)));
    if (choice == 1){
      do {
        cout << "Here are your attacks! Good luck Carti fan!\n1) Blue Shell\n2) CARTI\n3) YOUNGBOY\n4) Scar\n";//the user's attacks
      }  while((!(getValidInt(attack)) || (attack < 1) || (attack > 4)));
      if(attack == 1){
        cout << "You pulled out a Blue Shell from the fifth pocket in your cargo pants and threw it at Diddy! Much to your disappointment, Manky Kong is actually in first place and it blows up in his face instead. Your attack did no damage!\n";//what the attack does
        if (diddy > 0) {
          cout << "Diddy pulls out his coconut gun and deals " << random << " damage!\n";
          health = health - random;//what diddy does after your attack
        }
        if (health < 0) {
          health = 0;
        }
        if (diddy < 0) {
          diddy = 0;
        }
        cout << "Diddy HP: " << diddy << endl;
        cout << "Health: " << health << endl;//displays both player's health
      }
      else if (attack == 2) {
        cout << "You throw your Playboi Carti body pillow at Diddy! Diddy is flustered and slips on a banana peel! Your attack did 70 damage.\n";//what the attack does
        diddy = health - CARTI;
        if (diddy > 0) {
          cout << "Diddy pulls out his coconut gun and deals " << random << " damage!\n";
          health = health - random;//what diddy does after your attack
        }
        if (health < 0) {
          health = 0;
        }
        if (diddy < 0) {
          diddy = 0;
        }
        cout << "Diddy HP: " << diddy << endl;
        cout << "Health: " << health << endl;//displays both player's health
      }
      else if (attack == 3) {
        cout << "Diddy Kong being an absolute menace reminds you of the time you would blast Youngboy in gym class! You strap on the Black Air Force I's and dropkick him in the face! The power of Youngboy causes Diddy to lose 25 HP!\n";//what the attack does
        diddy = diddy - YOUNGBOY;
        if (diddy > 0) {
          cout << "Diddy pulls out his coconut gun and deals " << random << " damage!\n";
          health = health - random;//what diddy does after your attack
        }
        if (health < 0) {
          health = 0;
        }
        if (diddy < 0) {
          diddy = 0;
        }
        cout << "Diddy HP: " << diddy << endl;
        cout << "Health: " << health << endl;//displays both player's health
      }
      else if (attack == 4) {
        cout << "You whip out your Legendary Scar and start blasting in his direction! Even more so, you have Renegade Raider and he doesn't! Your true gamer energy simply outmatches Diddy and you deal 99 damage!\n";//what the attack does
        diddy = diddy - scar;
        if (diddy > 0) {
          cout << "Diddy pulls out his coconut gun and deals " << random << " damage!\n";
          health = health - random;//what diddy does after your attack
        }
        if (health < 0) {
          health = 0;
        }
        if (diddy < 0) {
          diddy = 0;
        }
        cout << "Diddy HP: " << diddy << endl;
        cout << "Health: " << health << endl;//displays both player's health
      }
    }
    else if (choice == 2) {
      cout << "You tried to impress Diddy Kong by playing Vamp Anthem. Diddy Kong is not impressed and says 'mid carti'\nYou lose 69 health from embarrassment!\n";
      health = health - 69;
      cout << "Diddy pulls out his coconut gun and deals " << random << " damage!\n";
      health = health - random;
      if (diddy < 0) {
          diddy = 0;
        }
      cout << "Diddy HP: " << diddy << endl;
      if(health < 0){
          health = 0;
      }
      cout << "Health: " << health << endl;//displays both player's health
    }
    else if (choice == 3) {
      if (heals == 3) {
       cout << "You consume a meddy betty! You gain back full health!\n" << endl;//what you use to heal
       health = 100; 
       heals--;//amount of heals goes down
      }
      else if (heals == 2) {
        cout << "You eat a bowl of your favorite cereal, Booty-O's! You gain 75 health\n"; //what you use to heal
        health = health + 75;
        if (health > 100) {
          health = 100;
        }
        heals--;//amount of heals goes down
      }
      else if (heals == 1) {
        cout << "You eat the Twizzler in your back pocket. You feel like scum. You gain 20 health!\n"; //what you use to heal
        health = health + 20;
        if (health > 100) {
          health = 100;
        }
        heals--;//amount of heals goes down
      }
      else {
        cout << "You are out of heals!\n";//if you have 0 heals you cant heal 
      }
      cout << "However, Diddy pulls out his coconut gun and deals " << random << " damage!\n";
      health = health - random;//after you heal diddy kong attacks
      if (health < 0) {
          health = 0;
      }//health cant be negative
      if (diddy < 0) {
          diddy = 0;
        }
      cout << "Diddy HP: " << diddy << endl;
      cout << "Health: " << health << endl;//displays both players health
    }
    else if (choice == 4) {
      cout << "You challenge Diddy Kong to a Fortnite 1v1! Unfortunately, Diddy played in the World Cup and boxes you in like a fish.\nLuckily, he misses the one pump and you only lose 15 health!\n";//description 
      health = health - 15;
      if (diddy > 0) {
        cout << "Diddy pulls out his coconut gun and deals " << random << " damage!\n";
        health = health - random;//diddy kong's attack
      }
      if (diddy < 0) {
          diddy = 0;
        }
      cout << "Diddy HP: " << diddy << endl;
      if(health < 0){
          health = 0;
      }//health cant be negative
      cout << "Health: " << health << endl;//displays both player's health
    }
  }
  return health;
}

int donkeykong(int health) {
  int donkey=150, CARTI = 99, star = 5, pushinP = 15, lotta = 30,heals = 3, choice, attack, random, dcount = 0;
  string dummy;
  //all the variables
  srand((unsigned) time(0));
   cout << "After defeating Carti hater, Diddy Kong, you have evolved to a Carti SUPER fan and gotten new moves!\n";//opening line
     cout << 
"───────────────▄████████▄────────\n"
"──────────────▄█▀───────▀██▄─────\n"
"───────────▄█▀───────────██──────\n"
"─────────▄█▀──────▄──────▐█▌─────\n"
"────────▄█────────▀█─────▐█▌─────\n"
"───────▄█──────────▀█───▄██──────\n"
"──────▄█────────────▀█─▄█▀█▄─────\n"
"─────▄█──────────────██▀───█▄────\n"
"────▄█──────────────────────█▄───\n"
"───▄█────────────────────────█▄──\n"
"──▄█───▄██████▄────▄█████▄────█──\n"
"──█───█▀─────▀█────█▀────▀█───█──\n"
"──█───█──▄────▀████▀───▄──█───█──\n"
"▄███▄─█▄─▐▀▄─────────▄▀▌─▄█─▄███▄\n"
"█▀──█▄─█─▐▐▀▀▄▄▄─▄▄▄▀▀▌▌─█─▄█──▀█\n"
"█────█─█─▐▐──▄▄─█─▄▄──▌▌─█─█────█\n"
"█─▄──█─█─▐▐▄─▀▀─█─▀▀─▄▌▌─█─█──▄─█\n"
"█──█─█─█──▌▄█▄▄▀─▀▄▄█▄▐──█─█─█──█\n"
"█▄─█████████▀──▀▄▀──▀█████████─▄█\n"
"─██▀──▄▀──▀──▀▄───▄▀──▀──▀▄──▀██\n"
"██─────────────────────────────██\n"
"█───────────────────────────────█\n"
"█─▄───────────────────────────▄─█\n"
"█─▀█▄───────────────────────▄█▀─█\n"
"█──█▀███████████████████████▀█──█\n"
"█──█────█───█───█───█───█────█──█\n"
"█──▀█───█───█───█───█───█───█▀──█\n"
"█───▀█▄▄█▄▄▄█▄▄▄█▄▄▄█▄▄▄█▄▄█▀───█\n"
"▀█───█──█───█───█───█───█──█───█▀\n"
"─▀█──▀█▄█───█───█───█───█▄█▀──█▀─\n"
"──▀█───▀▀█▄▄█───█───█▄▄█▀▀───█▀──\n"
"───▀█─────▀▀█████████▀▀─────█▀───\n"
"────▀█─────▄─────────▄─────█▀────\n"
"─────▀██▄───▀▀▀▀▀▀▀▀▀───▄██▀─────\n"
"────────▀██▄▄───────▄▄██▀────────\n"
"───────────▀▀███████▀▀───────────\n";

//DONKEY KONG CODE
  while (donkey > 0 || health > 0) {
    random = (rand() % 75) + 1;
    do {
      cout << "\nWhat will you do?\n";
      cout << "1) Attack\n2) Impress\n3) Heal\n4) Persuade\n5) Flirt\n";//what the user can do
    }  while((!(getValidInt(choice)) || (choice < 1) || (choice > 5)));
    if (choice == 1){
      do {
        cout << "Here are your attacks! Good luck Carti fan!\n1)Blue Shell\n2)PushinP\n3)Whole Lotta Red\n";//possible attacks the user can do
      }  while((!(getValidInt(attack)) || (attack < 1) || (attack > 4)));
      if(attack == 1){
        cout << "A star appears between you and Donkey Kong. You both jump for it but because of your enhanced skills because of Carti you reach it first. Suddenly the Mario Kart Music starts playing. Unfortunatly, Carti's music has turned off and your attack only does 5 damage!\n";//what the attack does
        donkey = donkey - 5;//donkey kong's health
        if (donkey > 0) {
          cout << "Donkey Kong throws a wooden barrel and deals " << random << " damage!\n";
          health = health - random;
        }//if donkey kong is still alive he attacks
        cout << "Donkey HP: " << donkey << endl;
        if(health < 0){
          health = 0;
        }//health cant be negative
        if (donkey < 0) {
          donkey = 0;
        }
        cout << "Health: " << health << endl;//displaying both player's health
      }
      else if(attack == 2){
        cout << "You are Pushin P. Gunna himself ascends to battle to help you! You guys give Donkey Kong the worst wet willy the world has ever seen and deal 15 health!";//what the attack does
        donkey = donkey - 15;//donkey kongs health
        if (donkey > 0) {
          cout << "Donkey Kong throws a wooden barell and deals " << random << " damage!\n";
          health = health - random;
        }//if donkey kong is still alive he attacks
        if (donkey < 0) {
          donkey = 0;
        }
        cout << "Donkey HP: " << donkey << endl;
        if(health < 0){
          health = 0;
        }//health cant be negative
        cout << "Health: " << health << endl;//displaying both player's health
      }
      else if(attack == 3){
        cout << "This entire time you have had your 2001 earbuds in! Carti's album, Whole Lotta Red, comes on. With the power of Whole Lotta Red in your blood you unleash an unbelivable attack! Suddenly Donkey Kong no longer has any ears because he can't handle peak! Donkey Kong loses 30 health!\n";//what the attack does
        donkey = donkey - 30;//donkey kongs health
        if (donkey > 0) {
          cout << "Donkey Kong throws a wooden barell and deals " << random << " damage!\n";
          health = health - random;
        }//if donkey kong is still alive he attacks
      if(donkey < 0){
        donkey = 0;
      }
      if(health < 0){
          health = 0;
        }//health cant be negative
        cout << "Donkey HP: " << donkey << endl;
        cout << "Health: " << health << endl;//displaying both player's health
      }
      else if(attack == 4){
        cout << "You are a true Carti fan. Carti himself comes out of the darkness and plays Vamp Anthem! You watch in amazement. Suddenly thousands of people start appearing and a huge moshpit forms. Donkey Kong gets stuck in the middle of it and loses 99 health!!\n";//what the attack does
        donkey = donkey - 99;//donkey kongs health
        if (donkey > 0) {
          cout << "Donkey got stuuned and cannot attack!\n";
        }//donkey cannot attack bc he is stunned
        cout << "Donkey HP: " << donkey << endl;
        cout << "Health: " << health << endl;//displaying both player's health
      }
    }
    
    if (choice == 2) {
      cout << "You try to impress Donkey Kong by playing your Carti playlist. However, he only listens to Call Me Maybe by Katy Perry. You gain 50 health from having better taste!\n"; 
      health = health + 50;
      cout << "Donkey HP: " << donkey << endl;
      cout << "Health: " << health << endl;
    }
     else if (choice == 3) {
      if (heals == 3) {
       cout << "You consume a big shield pot! You gain back full health!\n" << endl;
       health = 100; 
       heals--;
      }
      else if (heals == 2) {
        cout << "You drink a glass of expired milk! You gain 75 health\n";
        health = health + 75;
        if (health > 100) {
          health = 100;
        }
        heals--;
      }
      else if (heals == 1) {
        cout << "You eat the strange looking green thing in your pocket. It tastes funny but you gain 20 health!\n";
        health = health + 20;
        if (health > 100) {
          health = 100;
        }
        heals--;
      }
      else {
        cout << "You are out of heals!\n";
      }
      cout << "Donkey Kong throws a wooden barell and deals " << random << " damage!\n";
      health = health - random;
      if(donkey < 0){
        donkey = 0;
      }
      if(health < 0){
          health = 0;
        }//health cant be negative
      cout << "Donkey HP: " << donkey << endl;
      cout << "Health: " << health << endl;//displays both player's health
    }
    if (choice == 4){
      cout << "You think of a genius idea! Persuade Donkey Kong to not fight! Little did you know that Donkey Kong is God himself and sees through you. The power of Carti cannot block this attack. Donkey Kong throws a wooden barell and deals " << random << " damage!\n";
      health = health - random;
      if(health < 0){
          health = 0;
        }
      if(donkey < 0){
        donkey = 0;
      }
      cout << "Donkey HP: " << donkey << endl;
      cout << "Health: " << health << endl;//displaying both player's health
    }
    if (choice == 5) {
      cout << "You flirted with Donkey Kong. Unfortunately, he's already dating Mega Knight from Clash Royale!\nHe sucker punches you in the jaw and you lose 85 health!\n";
      health = health - 85;
      if(donkey < 0){
        donkey = 0;
      }
      if(health < 0){
          health = 0;
        }
      cout << "Donkey HP: " << donkey << endl;
      cout << "Health: " << health << endl;//displays both player's health
    }
  if(donkey <= 0){//if the player defeats donkey kong the winning message displays
    cout << "CONGRATS CARTI FAN! YOU HAVE DEFEATED THE LEGENDARY KONG DUO! HERE ARE YOUR PRIZES WARRIOR...";
    cout << "\nIn Donkey Kong's secret chest you find PLayboi Carti's real finger nail. There are other things in the chest such as a vile with the label 'Immortality Potion', but who really cares! You know have a fingernail from Carti himself.\n\n!GAME OVER!";
    break;
    }
  }
  return health;
}
