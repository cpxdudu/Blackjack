//this is a Blackjack game!
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string> 
using namespace std;

//the function of giving cards
int give(int num[52]){
	int card; int cards[1]; 
	srand(time(NULL));
	card = rand() % 52;
	card = num[card];
	while (card == 0){
		card = rand() % 52;
		card = num[card];
	}
	num[card - 1] = 0;
	cards[1] = card;
	return (cards[1]);
}

//print the cards, calculate the score
double dealing(int card){
	int num, flower; double num1;
	char num2;
	num = card % 13;
	flower = (card - 1) / 13;;
	switch(num){
		case 0: num2 = 'K'; 
				num1 = 0.5; break;
		case 1: num2 = 'A'; 
				num1 = 1; break;
		case 10: num1 = num;							//10 can't be a character 
			switch(flower){
					case 0: cout<< "Spade "<< num<< "  "; break;
					case 1: cout<< "Hearts "<< num<< "  "; break;
					case 2: cout<< "Club "<< num<< "  "; break;
					case 3: cout<< "Diamond "<< num<< "  "; break;
			}
			return num1;break;
		case 11: num2 = 'J'; 
				 num1 = 0.5; break;
		case 12: num2 = 'Q'; 
				 num1 = 0.5; break;
		default: num2 = num + '0' ;
				 num1 = num; 
	}
	switch(flower){
		case 0: cout<< "Spade "<< num2<< "  "; break;
		case 1: cout<< "Hearts "<< num2<< "  "; break;
		case 2: cout<< "Club "<< num2<< "  "; break;
		case 3: cout<< "Diamond "<< num2<< "  "; break;
	}
	return num1;
}

//main function
int main(){
	int Card1, Card2, Card3, help; double score, score1; 
	int card[52];
	int l;
	char choice;
	string choices="";
	for(int i=1; i<53;++i){
		card[i-1] = i;
	}
	score = 0;
	cout<< "Player Parts"<< endl<< "Players Cards"<<"  ";
	Card1 = give(card); score += dealing(Card1);
	Card2 = give(card); score += dealing(Card2);
	cout<< endl<< endl<< "Need one more cards?";
	getline(cin,choices);
	l=choices.length();
	while(l>1){
		cout<< "wrong character"<<endl;
		cout<< "Need one more cards?";
		getline(cin,choices);
		l=choices.length();
	}
	choice=choices[0];
	while (choice != 'y'&& choice != 'Y'&& choice != 'n'&& choice != 'N'){
		cout<< "wrong character"<<endl;
		cout<< "Need one more cards?";
		cin.sync();
		getline(cin,choices);
		l=choices.length();
		while(l>1){
			cout<< "wrong character"<<endl;
			cout<< "Need one more cards?";
			getline(cin,choices);
			l=choices.length();
		}
		choice=choices[0];
	} 
	while (choice == 'y'|| choice == 'Y'){
		cout<< endl<< "one more card:  ";
		Card3 = give(card); score += dealing(Card3);
		if (score > 21){
			cout<< endl<< "you lose"<< endl;
			break;
		} 
		cout<< endl<< "Need one more cards?";
		getline(cin,choices);
		l=choices.length();
		while(l>1){
			cout<< "wrong character"<<endl;
			cout<< "Need one more cards?";
			getline(cin,choices);
			l=choices.length();
		}
		choice=choices[0];
		while (choice != 'y'&& choice != 'Y'&& choice != 'n'&& choice != 'N'){
			cout<< "wrong character"<<endl;
			cout<< "Need one more cards?";
			cin.sync();
			getline(cin,choices);
			l=choices.length();
			while(l>1){
				cout<< "wrong character"<<endl;
				cout<< "Need one more cards?";
				getline(cin,choices);
				l=choices.length();
			}
			choice=choices[0];
		} 
	}
	if (score <= 21){
		cout<< endl<< endl<< "Computer Parts"<< endl<< "Computer's Cards"<< "  ";
		Card1 = give(card); score1 += dealing(Card1);
		Card2 = give(card); score1 += dealing(Card2);
		while (score1 <= score){
			cout<< endl<< "one more card:  ";
			Card3 = give(card); score1 += dealing(Card3);
			if (score1 > 21){
				cout<< endl<< "you win"<< endl;
				break;
			} 
			if (score1 > score){
				cout<< endl<< "you lose"<< endl;
			} 
		} 
	}
	cout<< "Try Again?";
	getline(cin,choices);
	l=choices.length();
	choice=choices[0];
	while (choice != 'y'&& choice != 'Y'&& choice != 'n'&& choice != 'N'){
		cout<< "wrong character"<<endl;
		cout<< "Try Again?";
		cin.sync();
		getline(cin,choices);
		l=choices.length();
		while(l>1){
			cout<< "wrong character"<<endl;
			cout<< "Try Again?";
			getline(cin,choices);
			l=choices.length();
		}
		choice=choices[0];
	}
	if (choice == 'Y'|| choice == 'y'){
		help = main();                     //restart
	}
	return 0; 
}

