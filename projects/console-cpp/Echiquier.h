#ifndef ECHIQUIER_H
#define ECHIQUIER_H

#include <iostream>
#include<string>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include<fstream>


using namespace std;
 typedef struct{
		int x; 				/*structure de vecteur qui va contenir les coordonnees des places possible (fou,tour,reine) */
		int y; 				
		}pos;
		
class Echiquier
{
	
	private :
		int t[8][8];
		int tj; 
		bool roque; 
		bool roque2; 
		bool roquegrand; 
		bool roquegrand2; 
		pos EnPassant,EnPassant2;
	public : 
		Echiquier(); 
		~Echiquier(); 
		//deplacement
		void VerifDepart();
		void VerifArriv(int x,int y);			
		vector<pos> clouageblanc();
		vector<pos> clouagenoire();
		vector<pos> posAposs(int x,int y); //choix des deplacements
		pos chercherroi(int roi);
		//mouvement piece
		void VerifFou(vector<pos> ta,int x,int y);
		void VerifTour(vector<pos>ta,int x,int y);
		void VerifRoi(vector<pos>ta,int x,int y);
		void VerifReine(vector<pos>ta,int x,int y);
		void VerifCav(vector<pos>ta,int x,int y);
		void VerifPion(vector<pos>ta,int x,int y);
		void VerifDragon(vector<pos> ta, int x, int y);
		//mouvements peciaux
		bool cherchercloue(vector<pos> t,int x,int y);
		int echecblanc(int &x1,int &y1,int x=-1,int y=-1);
		int echecnoir(int &x1,int &y1,int x=-1, int y=-1);
		void Promotion(int tj,int x1,int y1,int x,int y); 
		bool echec_et_mat();
		void setroque(bool ro); 
		void setgrandroque(bool ro);
		bool getroque(); 
		bool getgrandroque();
		void setroque2(bool ro); 
		void setgrandroque2(bool ro);
		bool getroque2(); 
		bool getgrandroque2();	
		void setEnPassant(pos a);
		void setEnPassant2(pos a); 
		//partie
		void print(); 
		void settj(int j);
		int gettj(); 
		void charger(); 
		int roiexiste();
		int getplateau(); 
		void jouer();
		int FinPartie();
		void sauvegarder();
};

#endif
