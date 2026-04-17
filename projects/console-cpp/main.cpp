#include <iostream>
#include<stdio.h>
#include"Echiquier.h"
using namespace std;
void menu(){ 		//Menu de jeu : 
	cout<<"1-NOUVELLE PARTIE : "<<endl<<"2-CHARGER UNE PARTIE : "<<endl<<"3-QUITTER :"<<endl;
}
int main() {
	 Echiquier a; int choix,i=1,j=1; pos b; pos c; 
	b.x = -1; b.y = -1;
	c.x = -1; c.y = -1;
	bool fin=false; int continuer;
menu();   
do{
	cin>>choix; 
switch(choix) {
case 1 : break; 	
case 2 : a.charger(); break;  	
case 3 : fin=true; break; 
default : break; 	
}	}while(choix<1 || choix>3);  
if(fin==false){   //case 3 de switch fait quitter de jeu alors si le jour veut quitter alors on fait rien sinon on affiche le plateau et j'organise le tour apres chaque jeu tant que les rois de deux joueur existes : 
do{
	continuer=0;
a.print(); 
a.jouer();
if(i%2 == 0 )
{
	 b.y=-1; 
	b.x=-1;  a.setEnPassant(b);
	i=1;
	 }
if(j%2==0)
		 {
		 	c.x=-1;  
			c.y=-1; a.setEnPassant2(c);
			j=1; 
		 }  
if(a.echec_et_mat()==false) //pour tester si il ya un echec et mat avant que les tours changent;   
	continuer=1;
if (a.gettj()==1){
	i+=1;
	a.settj(2); }
else {
a.settj(1);j+=1;
}

}while(a.FinPartie()==1 && continuer==1);
}
}

