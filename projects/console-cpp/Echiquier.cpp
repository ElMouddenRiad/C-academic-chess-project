#include "Echiquier.h"

Echiquier::Echiquier(){
	for (int i=0;i<8;i++){					// initialisation  du plateau (les pions) : 
		t[1][i]=1;
		t[6][i]=-1;  	
		}

t[0][0]=3;
t[0][1]=2;
t[0][2]=4;							// les autres pieces (le joueur 1 --> positif valeur) 
t[0][3]=5;												//(le joueur 2 --> negatif valeur)									
t[0][4]=6;
t[0][5]=4;
t[0][6]=2;
t[0][7]=3;
t[7][0]=-3;
t[7][1]=-2;
t[7][2]=-4;			
t[7][3]=-5;
t[7][4]=-6;
t[7][5]=-4;
t[7][6]=-2;
t[7][7]=-3;
		for(int i=2;i<6;i++){
			for(int j=0;j<8;j++){
				t[i][j]=0; 
			}
				}
srand(time(NULL)); //a chaque execution se change la valeur . 
tj=2;    //tour de joueur avec random aleatoire (1 ou 2) 	
	 roque=true; 
	 roque2=true; 
	 roquegrand=true; 
	 roquegrand2=true;
}
void Echiquier::print() 
{
	cout<<"colonne : |      0      |      1      |      2      |      3      |      4      |      5      |      6      |      7      "<<endl;
	cout<<"          _____________________________________________________________________________________________________________"<<endl;
for(int i=0;i<8;i++){
	cout<<"ligne :"<<i<<" ";
	for(int j=0;j<8;j++){
		if(t[i][j]==1){					
			cout<<" | BLACKPAWN  "; 
		} 
		else if(t[i][j]==-1){
			cout<<" | WHITEPAWN  "; 
		}
		else if(t[i][j]==3){ 
			cout<<" | BLACKROOK  "; 
		}
		else if(t[i][j]==- 3 )
		cout<<" | WHITEROOK  "; 
		else if(t[i][j]==2 ){
			cout<<" | BLACKKNIGHT"; 
		}
		else if(t[i][j]==-2){
			cout<<" | WHITEKNIGHT"; 
		}
		else if (t[i][j]==4 ){
			cout<<" | BLACKBISHOP"; 
		}
		else if(t[i][j]==-4){
			cout<<" | WHITEBISHOP";
		}
		else if(t[i][j]==5){
			cout<<" | BLACKQUEEN "; 
		}
		else if(t[i][j]==-5){
			cout<<" | WHITEQUEEN "; 
		}
		else if(t[i][j]==6){
			cout<<" | BLACKKING  "; 
		}
		else if(t[i][j]==-6){
			cout<<" | WHITEKING  "; 
		}
		if(t[i][j]==0){
			cout<<" |            "; 
		}
	}
	cout<<endl;
		cout<<"          _____________________________________________________________________________________________________________"<<endl; 
}	
}
int Echiquier::echecblanc(int &x1,int &y1,int x, int y ){  // les variables x et y sont facultatif en cas de cherche si le roi est en echec : 
int i,j,a,b; 
if(x<0 || x>=8 || y<0 || y>=8){
for( i=0;i<8;i++){
	for( j=0;j<8;j++){
		if(t[i][j]==6){
			a=i; b=j; 
			j=8; i=8; 
		}
	}
}
i=a; j=b;
}
else {
	i=x; j=y; a=x; b=y; 
}
if(a+1<8 && b-1>=0 && t[a+1][b-1]==-1){
	return 1;
}
if(a+1<8 && b+1<8 && t[a+1][b+1]==-1){
	return 1;
}
a=i+2; b=j-1; 
	if(a<8 && b>=0 && t[a][b]==-2)
		return 1; 
a=i-2; b=j+1;		
	if(a>=0 && b<8 && t[a][b]==-2)
		return 1; 
b=j-1;
	if(a>=0 && b>=0 && t[a][b]==-2)
		return 1; 
					
a=i+2; b=j+1; 
	if(a<8 && b<8 && t[a][b]==-2)
		return 1;
a=i+1; b=j+2;
	if(a<8 && b<8 && t[a][b]==-2)
		return 1;
b=j-2; 		
	if(a<8 && b>=0 && t[a][b]==-2)
		return 1;
a=i-1; b=j+2;
	if(a>=0 && b<8 && t[a][b]==-2)
		return 1;		
a=i-1; b=j-2;
	if(a>=0 && b>=0 && t[a][b]==-2)
		return 1;

//cas de roi d'ennemie : 

if(i+1<8 && t[i+1][j]==-6)
	return 1; 	
if(i-1>=0 && t[i-1][j]==-6)
	return 1; 	
if(i+1<8 && j+1<8 && t[i+1][j+1]==-6 )
	return 1; 
if(i+1<8 && j-1>=0 && t[i+1][j-1]==-6)
	return 1; 
if(i-1>=0 && j-1>=0 && t[i-1][j-1]==-6)
	return 1; 
if(i-1>=0 && j+1<8 && t[i-1][j+1]==-6)
	return 1; 
if(j-1>=0 && t[i][j-1]==-6)
	return 1; 
if(j+1<8 && t[i][j+1]==-6)
	return 1;

// cas de la tour :  
a=i+1; 
while(a<8){
if(t[a][j]==-3 || t[a][j]== -5)	
	{
		x1=a; y1=j; 
	return 1;	
	}
if(t[a][j]==0)
a++; 
else 
a=8;	
} 
a=i-1;
while(a>=0){
	if(t[a][j]==-3|| t[a][j]== -5)	{
		x1=a; y1=j; return 1;
	}
	if(t[a][j]==0)
		a--;
	else 
		a=-1; 	
}
b=j-1; 
while(b>=0){
	if(t[i][b]==-3||t[i][b]== -5){
		x1=i; y1=b; 	return 1; 
	}
	if(t[i][b]==0)	
		b--; 
	else 
		b=-1; 				
}
b=j+1; 
while(b<8){
	if(t[i][b]==-3|| t[i][b]== -5){
		x1=i;y1=b; 	return 1; 
	}
	if(t[i][b]==0)
		b++;
	else 
		b=8; 	
}
/// le cas du fou : 
a=i+1; b=j+1; 
while(a<8 && b<8){
	if(t[a][b]== -4|| t[a][b]== -5){
		x1=a;y1=b;	return 1;
	}
	if(t[a][b]==0){
		a++;b++;
	}
	else 
		a=8; 
}
a=i+1; b=j-1; 
while(a<8 && b>=0){
if(t[a][b]== -4|| t[a][b]== -5){
		x1=a; y1=b;	return 1;
		}
	if(t[a][b]==0){
		a++;b--;}
	else 
		a=8; 
}
a=i-1; b=j-1; 
while(a>=0 && b>=0){
	if(t[a][b]== -4|| t[a][b]== -5)
		{
		x1=a; y1=b;	return 1;
		}
	if(t[a][b]==0){
		a--;b--;}
	else 
		a=-1; 
}
a=i-1;b=j+1;
while(a>=0 && b<8){
	if(t[a][b]== -4 || t[a][b]== -5)
		{
		x1=a; y1=b;	return 1;
		}
	if(t[a][b]==0){
		a--;b++;}
	else 
		b=8; 
}
return 0; 
}

int Echiquier::echecnoir(int &x1,int &y1,int x, int y){  // les variables x et y sont facultatif en cas de cherche si le roi est en echec : 
int i,j,a,b; 
if(x<0 || x>=8 || y<0 || y>=8){
for( i=0;i<8;i++){
	for( j=0;j<8;j++){
		if(t[i][j]==-6){
			a=i; b=j; 
			break; 
		}
	}
}
i=a; j=b;
}
else {
	i=x; j=y; a=x; b=y; 
}
if(a-1>=0 && y-1>=0 && t[a-1][y-1]==1){
	return 1;
}
if(a-1>=0 && y+1<8 && t[a-1][y+1]==1){
	return 1;
}
a=i+2; b=j-1;
	if(a<8 && b>=0 && t[a][b]==2)
		return 1; 
a=i-2; b=j+1;		
	if(a>=0 && b<8 && t[a][b]==2)
		return 1; 
b=j-1;
	if(a>=0 && b>=0 && t[a][b]==2)
		return 1; 
					
a=i+2; b=j+1; 
	if(a<8 && b<8 && t[a][b]==2)
		return 1;
a=i+1; b=j+2;
	if(a<8 && b<8 && t[a][b]==2)
		return 1;
b=j-2; 		
	if(a<8 && b>=0 && t[a][b]==2)
		return 1;
a=i-1; b=j+2;
	if(a>=0 && b<8 && t[a][b]==2)
		return 1;		
a=i-1; b=j-2;
	if(a>=0 && b>=0 && t[a][b]==2)
		return 1;

//cas de roi d'ennemie : 

if(i+1<8 && t[i+1][j]==6)
	return 1; 	
if(i-1>=0 && t[i-1][j]==6)
	return 1; 	
if(i+1<8 && j+1<8 && t[i+1][j+1]==6 )
	return 1; 
if(i+1<8 && j-1>=0 && t[i+1][j-1]==6)
	return 1; 
if(i-1>=0 && j-1>=0 && t[i-1][j-1]==6)
	return 1; 
if(i-1>=0 && j+1<8 && t[i-1][j+1]==6)
	return 1; 
if(j-1>=0 && t[i][j-1]==6)
	return 1; 
if(j+1<8 && t[i][j+1]==6)
	return 1;

// cas de la tour :  
a=i+1; 
while(a<8){
if(t[a][j]==3 || t[a][j]== 5)
	{ x1=a; y1=j;
	return 1;
		}	
if(t[a][j]==0)
a++; 
else 
a=8;	
}
a=i-1;
while(a>=0){
	if(t[a][j]==3|| t[a][j]== 5)	
		{ x1=a; y1=j;
	return 1;
		}
	if(t[a][j]==0)
		a--;
	else 
		a=-1; 	
}
b=j-1; 
while(b>=0){
	if(t[i][b]==3||t[i][b]== 5)
		{ x1=i; y1=b;
	return 1;
		}
	if(t[i][b]==0)	
		b--; 
	else 
		b=-1; 				
}
b=j+1; 
while(b<8){
	if(t[i][b]==3|| t[i][b]==5)
		{ x1=i; y1=b;
	return 1;
		}
	if(t[i][b]==0)
		b++;
	else 
		b=8; 	
}
/// le cas du fou : 
a=i+1; b=j+1; 
while(a<8 && b<8){
	if(t[a][b]== 4|| t[a][b]==5)
		{ x1=a; y1=b;
	return 1;
		}
	if(t[a][b]==0){
		a++;b++;}
	else 
		a=8; 
}
a=i+1; b=j-1; 
while(a<8 && b>=0){
if(t[a][b]== 4|| t[a][b]== 5)
		{ x1=a; y1=b;
	return 1;
		}
	if(t[a][b]==0){
		a++;b--;}
	else 
		a=8; 
}
a=i-1; b=j-1; 
while(a>=0 && b>=0){
	if(t[a][b]== 4|| t[a][b]== 5)
		{ x1=a; y1=b;
	return 1;
		}
	if(t[a][b]==0){
		a--;b--;}
	else 
		a=-1; 
}
a=i-1;b=j+1;
while(a>=0 && b<8){
	if(t[a][b]== 4 || t[a][b]== 5)
		{ x1=a; y1=b;
	return 1;
		}
	if(t[a][b]==0){
		a--;b++;}
	else 
		b=8; 
}
return 0;
}

void Echiquier::Promotion(int tj,int x1,int y1,int x,int y){		//chercher une piece a changer en cas de pion est arriv� au ligne 0 ou ligne 7 (sa depend du joueur): 

	vector<int> t1; int l=0,cp,choix;
	t1.clear();									//on va stocker les pieces qui peut les remplacer avec se pion dans un vecteur . 
for(int k=2;k<6;k++){										//si c'est pas la reine et cp!=2 sa veut dire que cette piece existe une seule fois ou n'existe pas .  
if(tj==1)	
t1.push_back(k);
else 
 t1.push_back(-k);
}

if(t1.size()!=0){											//si le tableau contient au moin une piece manquante on l'affiche : 
for(int i=0;i<t1.size();i++){
	if(t1[i]==2)
		cout<<i<<"----->BLACKKNIGHT"<<endl;				//juste pour l'affichage des pieces manquantes pour qu'il choisit la piece qui veut la remplacer
	else if (t1[i]==-2)
		cout<<i<<"----->WHITEKNIGHT"<<endl;
	else if (t1[i]==4)
		cout<<i<<"----->BLACKBISHOP"<<endl;
	else if (t1[i]==-4)
		cout<<i<<"----->WHITEBISHOP"<<endl;
	else if (t1[i]==5)
		cout<<i<<"----->BLACKQUEEN"<<endl;
	else if (t1[i]==-5)
		cout<<i<<"----->WHITEQUEEN"<<endl;
	else if (t1[i]==3)
		cout<<i<<"----->BLACKROOK"<<endl;
	else if (t1[i]==-3)
		cout<<i<<"----->WHITEROOK"<<endl;
}
do{
	cout<<"donner la piece a remplacer : "; cin>>choix;		//choisir la piece a remplacer (pion avec une piece manquante) : 
}while(choix>t1.size()-1);
t[x1][y1]=t1[choix];
t[x][y]=0;
}
}

	//-------------------verifier la position d'arriver : 
void Echiquier::VerifArriv(int x,int y){		//j'entre avec tab et le tour et la pos de depart :  
	int x1,y1; bool jouer=false;	string ques; 
	
	do{	
		do {
		cout<<"donner le ligne d'arrivee : "; cin>>x1; 
		cout<<"donner la colonne d'arrivee : "; cin>>y1; 
}while(x1>7 || x1<0 || y1>7 || y1<0);  						//j'accepte les position qui sont entre 0 et 7 (dim de plateau)
if(x-x1==2 && tj==2 && t[x][y]==-1 && x==6 && t[x-2][y]==0 && y==y1 || (y==y1 && x-x1==1 && tj==2 && t[x][y]==-1 && t[x-1][y]==0) || x1-x==2 && tj==1 && t[x][y]==1 && x==1 && t[x+2][y]==0 && y==y1|| (x1-x==1 && tj==1 && t[x][y]==1 && t[x1][y]==0 && y==y1)){
	if(t[x][y]==-1 && x1==0){																//la premiere if : represente si la dif entre dep et arv est 2 ligne et la meme colonne et si la ligne est 6 (la premiere position de pion). 
		Promotion(2,x1,y1,x,y); jouer=true;	//en cas que le pions de 2eme joueur est arriv� a la ligne 0 de 1er joueur  					 //ou si la dif dep et arv est 1 et cette position est libre toujours on traitant le pions . est la suite c'est la meme chose pour l'autre joueur. 
	}else if(t[x][y]==1 && x1==7){					//le cas de l'autre joueur : 					
		Promotion(1,x1,y1,x,y); jouer=true;
	}
	 else if (t[x][y]==-1){			//avancement normal de pions de 2eme joueur: 
		t[x1][y1]=-1; jouer=true;
		t[x][y]=0;  
		if(x-x1==2){
			EnPassant2.x=x1;
			EnPassant2.y=y1;
		}
		}
	else {					//avancement de premier joueur : 
	  t[x1][y1]=1; 
  		t[x][y]=0; jouer=true;	
		if(x1-x==2){
			EnPassant.x=x1;
			EnPassant.y=y1;
		}
		}
}
else if(tj==2 && t[x][y]==-1 && t[x1][y1]>0 && x-x1==1 && abs(y-y1)==1){	//le cas que le pions attrape une piece de l'autre joueur on fait la dif des colonnes de dep et arv si c'est egale a 1 et les ligne aussi avec valeur absolue: 
	 if(t[x][y]==-1 && x1==0){			//cas qu'il attrape une piece qui est a la ligne 0 donc il doit remplacer ce pions avec une piece manquante si il a un manque de piece.  
		Promotion(2,x1,y1,x,y); jouer=true; 
	}else {							//sinon c'est un attrape normal on vas rien remplacer . 
	t[x1][y1]=-1; jouer=true;
	t[x][y]=0;
	}
}
else if(tj==1 && t[x][y]==1 && t[x1][y1]<0 && x1-x==1 && abs(y-y1)==1){	//meme travaille de dernier else if mais pour le premier joueur . 
	if(t[x][y]==1 && x1==7){
		Promotion(1,x1,y1,x,y); jouer=true;
	}else {
	t[x1][y1]=1; jouer=true;
	t[x][y]=0;
	}
}
else if ((tj==2 && t[x][y]==-1 && x!=6 && x-x1==2) || (tj==1 && t[x][y]==1 && x!=1 && x-x1==2)){		//en cas que le joueur veut deplacer un pions avec deux case et il n'a pas le droit alors on affiche un msg . 
	cout<<"----------------------------cette piece a deja ete deplacee par 2 cases !! "<<endl; 
}
/////// prise en passant :
else if(tj==2 && t[x][y]==-1 && x==3 && (y-1==EnPassant.y || y+1==EnPassant.y) && x==EnPassant.x && t[x1][y1]==0 && y1==EnPassant.y)
{
	t[x1][y1]=-1; jouer=true;
	t[x1+1][y1]=0;
	t[x][y]=0; 
}
else if(tj==1 && t[x][y]==1 && x==4 && (y-1==EnPassant2.y || y+1==EnPassant2.y) && x==EnPassant2.x && t[x1][y1]==0 && y1==EnPassant2.y){
	t[x1][y1]=1; 
	t[x1-1][y1]=0; 
	t[x][y]=0; jouer=true; 
}
///////
else if(t[x][y]==-2 &&tj==2 &&  t[x1][y1]>=0 && (abs(x-x1)==2 && abs(y-y1)==1 || abs(x-x1)==1 && abs(y-y1)==2)){ //le cas de cavalier je teste si (la dif entre les lignes egale a 2 et les colonne 1 ou la dif entre les ligne 1  et les colonne 2)
	t[x1][y1]=-2; 
	t[x][y]=0; jouer=true;
}
else if (t[x][y]==2 && tj==1 && t[x1][y1]<=0 && (abs(x-x1)==2 && abs(y-y1)==1 || abs(x-x1)==1 && abs(y-y1)==2))	// meme travaille au joueur 1 : 
{
	t[x1][y1]=2; 
	t[x][y]=0;  jouer=true;
}

if (jouer==false){						//si le joueur n'a pas jouer (si il a trompper les pos d'arriver ou qlq chose comme sa
	cout<<"tu veux changer la piece a jouer ? (o/n)"; cin>>ques;    //s'il veut changer de piece a jouer 
if (ques=="o") jouer=true; 									// si oui alors on sort de while avec jouer = true 
}
}while(jouer==false); if (ques=="o") VerifDepart();		//et on appelle pos depart
} 


//-----------------position d'arriver possible : 
vector<pos> Echiquier::posAposs(int x,int y) {
int i,j,a,b; pos p; 
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}; // D�placements en x
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // D�placements en y
												/*le resum� de cette fonction il retourne les positions possible de fou et tour et roi et reine dans un vector et apres*/
vector<pos> ta; int done;															//on affiche le vector pour choisir la position a deplacer . 
ta.clear();
if(t[x][y]==4 ||t[x][y]==-4 || t[x][y]==5 || t[x][y]==-5){	//***************************----->cas de fou ou de reine car la reine se deplace avec la combinaison de four et tour . 
	int i; int j; 
	i=x+1; j=y+1; 
while(i<=7 && j<=7){  									//traitement de diagonnale a droite en haut: 
if(t[i][j]==0){p.x=i; p.y=j; 
	ta.push_back(p); i++; j++;  
}else if((t[x][y]==4 || t[x][y]==5) && t[i][j]<0){
p.x=i; p.y=j; 
	ta.push_back(p);
j++; i++; i=8; }
else if (t[x][y] == 7 || t[x][y] == -7) {							//traitement des mouvements possibles du dragon 
	for (int k = 0; k < 8; k++) {
            int i = x + dx[k];
            int j = y + dy[k];
            
            while (i >= 0 && i <= 7 && j >= 0 && j <= 7) {
                if (t[i][j] == 0) {
                    pos p;
                    p.x = i;
                    p.y = j;
                    ta.push_back(p);
                } else if ((t[x][y] == 6 && t[i][j] < 0) || (t[x][y] == -6 && t[i][j] > 0)) {
                    pos p;
                    p.x = i;
                    p.y = j;
                    ta.push_back(p);
                    break; // Arr�ter le d�placement dans cette direction
                } else {
                    break; // Arr�ter le d�placement dans cette direction
                }
                
                i += dx[k];
                j += dy[k];
            }
        }
    }
else if((t[x][y]==-4 || t[x][y]==-5) && t[i][j]>0){
p.x=i; p.y=j; 
	ta.push_back(p);
j++; i++;
i=8;
}
else {
	i=8;
}
}
i=x-1; j=y-1; 
while(i>=0 && j>=0){						//traitement de diagonnale a gauche en bas : 
if(t[i][j]==0){cout<<i<<"   "<<j<<endl;
	p.x=i; p.y=j; cout<<p.x<<"   "<<p.y<<endl;
	ta.push_back(p); i--; j--; 
}else if((t[x][y]==4 || t[x][y]==5) && t[i][j]<0){
	p.x=i; p.y=j; 
	ta.push_back(p);
j--; i--; i=-1;
}
else if((t[x][y]==-4 || t[x][y]==-5) && t[i][j]>0){
	p.x=i; p.y=j; 
	ta.push_back(p);
j--; i--; i=-1;	
}else {
	i=-1; 
}
}
i=x-1; j=y+1; 
while(i>=0&& j<=7){							//traitement de diagonnale droite en bas : 
if(t[i][j]==0){
	p.x=i; p.y=j; ta.push_back(p); 
	i--; j++; 
}
else if((t[x][y]==4 || t[x][y]==5) && t[i][j]<0){
		p.x=i; p.y=j; 
	ta.push_back(p);
j++; i--; i=-1;
}
else if ((t[x][y]==-4 || t[x][y]==-5) && t[i][j]>0){
		p.x=i; p.y=j; 
	ta.push_back(p);
j++; i--; i=-1;	
}
else i=-1; 

}
i=x+1; j=y-1; 
while(i<=7 && j>=0){				//traitement de diagonnale a gauche en haut : 

if(t[i][j]==0){
	p.x=i; p.y=j; ta.push_back(p); 
	i++; j--; 
}
else if((t[x][y]==4 || t[x][y]==5) && t[i][j]<0){		 
		p.x=i; p.y=j; 
	ta.push_back(p);
j--; i++; i=8;
}
else if ((t[x][y]==-4 || t[x][y]==-5) && t[i][j]>0){
		p.x=i; p.y=j; 
	ta.push_back(p);
j--; i++; i=8;	
}
else i=8; 

}
}


if (t[x][y]==3 || t[x][y]==-3 || t[x][y]==5 || t[x][y]==-5){  //------------------------------cas de tour et la reine : 
	int i=x+1;  
	while(i<=7){    							//traitement de la verticale en haut 
		if(t[i][y]==0){
			p.x=i; p.y=y; 
			ta.push_back(p); 
			i++; 
		}else if((t[x][y]==3 || t[x][y]==5) && t[i][y]<0){
			p.x=i; p.y=y; ta.push_back(p); 
			i=8; 
		}else if((t[x][y]==-3 || t[x][y]==-5) && t[i][y]>0){
			p.x=i; p.y=y; ta.push_back(p); 
			i=8; 
		}else {
			i=8; 
		}
		
	}
i=x-1; 	
while(i>=0){								//traitement du verticale en bas : 
	if(t[i][y]==0){
			p.x=i; p.y=y; 
			ta.push_back(p); 
			i--; 
		}else if((t[x][y]==3 || t[x][y]==5) && t[i][y]<0){
			p.x=i; p.y=y; ta.push_back(p); 
			i=-1; 
		}else if((t[x][y]==-3 || t[x][y]==-5) && t[i][y]>0){
			p.x=i; p.y=y; ta.push_back(p); 
			i=-1; 
		}else {
			i=-1; 
		}
}
int j=y+1; 
while(j<=7){											//traitement de l'horizontale droite : 
if(t[x][j]==0){
	p.x=x; p.y=j; 
			ta.push_back(p); 
			j++; 
}else if((t[x][y]==3 || t[x][y]==5) && t[x][j]<0){
	p.x=x; p.y=j; ta.push_back(p); 
			j=8; 
}
else if((t[x][y]==-3 || t[x][y]==-5) && t[x][j]>0){
			p.x=x; p.y=j; ta.push_back(p); 
			j=8;
}else j=8;

}
j=y-1; 
while(j>=0){								//traitement de l'horizontale a gauche : 
if(t[x][j]==0){
	p.x=x; p.y=j; 
			ta.push_back(p); 
			j--; 
}else if((t[x][y]==3 || t[x][y]==5) && t[x][j]<0){
	p.x=x; p.y=j; ta.push_back(p); 
			j=-1; 
}
else if((t[x][y]==-3 || t[x][y]==-5) && t[x][j]>0){
			p.x=x; p.y=j; ta.push_back(p); 
			j=-1;
}else j=-1;

}

}

if(t[x][y]==6 || t[x][y]==-6){		//-------------------------cas de roi : 
	int j=y-1; 
	if(j>=0 && t[x][j]==0){
	p.x=x; p.y=j;
		ta.push_back(p);
	} j=y+1; 
	if(j<=7 && t[x][j]==0){
		p.x=x; p.y=j;
		ta.push_back(p);
	} j=y;
	int i=x+1; 
		if(i<=7 && t[i][y]==0){
		p.x=i; p.y=y;
		ta.push_back(p);}
i=x-1;
		if(i>=0 && t[i][y]==0){
		p.x=i; p.y=y;
		ta.push_back(p);}
i=x+1,j=y+1; 
	while(j<=7 && i<=7 && j!=y+2){
	if(t[i][j]==0){
		p.x=i; p.y=j;
		ta.push_back(p);
		j++; 
	}else if(t[x][y]==6 && t[i][j]<0)
	{
		p.x=i;   p.y=j; ta.push_back(p); 
		j=8;  
	}
	else if(t[x][y]==-6 && t[i][j]>0){
		p.x=i;   p.y=j; ta.push_back(p); 
		j=8; 
	}
		else 
		j=8; 
	}
	j=y-1; 
	while(j>=0 && i<=7 && j!=y-2){
	if(t[i][j]==0){
		p.x=i; p.y=j;
		ta.push_back(p);
		j--; 
	}else if(t[x][y]==6 && t[i][j]<0)
	{
		p.x=i;   p.y=j; ta.push_back(p); 
		j=-1;  
	}
	else if(t[x][y]==-6 && t[i][j]>0){
		p.x=i;   p.y=j; ta.push_back(p); 
		j=-1; 
	}
		else 
		j=-1; 	
		
	}
	i=x-1; j=y+1; 
	while(j<=7 && i>=0 && j!=y+2){
		if(t[i][j]==0){
		p.x=i; p.y=j;
		ta.push_back(p);
		j++; 
	}else if(t[x][y]==6 && t[i][j]<0)
	{
		p.x=i;   p.y=j; ta.push_back(p); 
		j=8;  
	}
	else if(t[x][y]==-6 && t[i][j]>0){
		p.x=i;   p.y=j; ta.push_back(p); 
		j=8; 
	}
		else 
		j=8; 	
	}
	j=y-1; 
		while(j>=0 && i>=0 && j!=y-2){
		if(t[i][j]==0){
		p.x=i; p.y=j;
		ta.push_back(p);
		j--; 
	}else if(t[x][y]==6 && t[i][j]<0)
	{
		p.x=i;   p.y=j; ta.push_back(p); 
		j=-1;  
	}
	else if(t[x][y]==-6 && t[i][j]>0){
		p.x=i;   p.y=j; ta.push_back(p); 
		j=-1; 
	}
		else 
		j=-1; 	
	}	
		
		if((roque2==true || roquegrand2==true) && t[x][y]==-6 && echecnoir(a,b,x,y)==0 && (t[x][7]==-3 || t[x][0]==-3)){
			if(t[x][7]==-3 && roque2==true){
			done=0;
			// le petit roque a droite : 
			for(int j=5;j<7;j++){
				if(t[7][j]!=0){
					done++; j=7;
				}
				if(echecnoir(a,b,7,j)==1){
					done++; j=7; 
				}
			}
			if(done==0){
			pos a; 
			a.x=7; a.y=6; 
			ta.push_back(a);
			cout<<endl<<"Il est possible de roquer !"<<endl; 
			}}
			if(t[x][0]==-3 && roquegrand2==true){
			done=0;
			for(int j=2;j<4;j++){
				if(t[7][j]!=0){
					done++; j=7;
				}
				if(echecnoir(a,b,7,j)==1){
					done++; j=7; 
				}	
			}
			if(done==0){
			pos b; 
			b.x=7; b.y=2; 
			ta.push_back(b);
			}	}
			}
			
		else if((roquegrand==true ||roque==true) && t[x][y]==6 && echecblanc(a,b,x,y)==0 && (t[0][7]==3 || t[0][0]==3)){
			if(t[0][7]==3 && roque==true){
			done=0;
			for(int j=5;j<7;j++){
				if(t[0][j]!=0){
					done++; j=7;
				}
				if(echecblanc(a,b,0,j)==1){
					done++; j=7;
				}
			}
			if(done==0){
			pos a; 
			a.x=0; a.y=6; 
			ta.push_back(a);
			cout<<endl<<"Il est possible de roquer !"<<endl; 
			}}
			if(t[0][0]==3 && roquegrand==true){
			
			done=0; 
			for(int j=2;j<4;j++){
				if(t[0][j]!=0){
						done++; j=7;
					}
					if(echecblanc(a,b,0,j)==1){
						done++; j=7;
					}
			}
			if(done==0){
			pos b; 
			b.x=0; b.y=2; 
			ta.push_back(b);
			}	}
		}
}
	return ta; 			//a la fin on retourne le tableau de positions : 
}

//--------------------les mvmnt du FOU : 
void Echiquier::VerifFou(vector<pos> ta,int x,int y){
	int choix; 
for(int i=0;i<ta.size();i++){										//on affiche le tableau ta (contient les position possible) et on demande de choisir la place :
		cout<<i<<"---->"<<ta[i].x<<"   "<<ta[i].y<<endl; 	
	}
do{
	cout<<"donner le choix du deplacement : "; cin>>choix; 
}while(choix<0 || choix>ta.size()-1);
if(t[x][y]==4){																// on effectue le mvt de piece :
t[x][y]=0; t[ta[choix].x][ta[choix].y]=4;
}else {
	t[x][y]=0; t[ta[choix].x][ta[choix].y]=-4;
}
}
//---------------------les mvmts du TOUR :  
void Echiquier::VerifTour(vector<pos>ta,int x,int y){
	int choix; 																					
	for(int i=0;i<ta.size();i++){														//meme travaille pour la tour .
		cout<<i<<"---->"<<ta[i].x<<"   "<<ta[i].y<<endl; 	
	}
do{
	cout<<"donner le choix du deplacement : "; cin>>choix; 
}while(choix<0 || choix>ta.size()-1);
if(t[x][y]==3){
	t[ta[choix].x][ta[choix].y]=3; 
	t[x][y]=0; 
	if(x==0 && y==7) 
		 roque=false;
	else if(x==0 && y==0)
		roquegrand=false; 	
}else { 
	t[ta[choix].x][ta[choix].y]=-3; 
	t[x][y]=0; 
	if(x==7 && y==7)
	roque2=false; 
	else if(x==7 && y==0)
		roquegrand2=false; 
}
}
/*bool Echiquier::move(int ld, int cd, int la, int ca)
{
    if (t[ld][cd] == -5 || t[ld][cd] == 5)
    {
        if (verifCav(ld, cd, la, ca))
        {
            t[la][ca] = t[ld][cd];
            t[ld][cd] = 0;
        }
        else
        {
            cout << "Mouvement Cavalier impossible" << endl;
        }
    }
    else if (t[ld][cd] == -6 || t[ld][cd] == 6)
    {
        if (verifPawn(ld, cd, la, ca))
        {
            if (t[0][ca] == 1 && t[la][ca] == 0)
            {
                cout << "Prise en diagonale impossible, pas de piece a prendre" << endl;
            }
            else if (verifPawn(ld, cd, la, ca) == 2)
            {
                cout << "Prise en diagonale impossible, la piece est de la meme couleur" << endl;
            }
            else if (enPassant(ld, cd, la, ca)) 
            {
                // Si c'est le cas, supprime le pion adverse �ligible
                int position[2];
                position[0] = (ld + la) / 2;
                position[1] = cd;
                t[position[0]][position[1]] = 0;

                // D�place le pion normalement
                t[la][ca] = t[ld][cd];
                t[ld][cd] = 0;

                cout << "Prise en passant effectu�e" << endl;
            }
            else
            {
                t[la][ca] = t[ld][cd];
                t[ld][cd] = 0;
            }
            nbMouvements++;
            if (abs(ld-la) == 2) {
                pionEnPassant[0] = nbMouvements + 1;
                pionEnPassant[1] = cd;
            } else {
                pionEnPassant[0] = -1;
                pionEnPassant[1] = -1;
            }
        }
        else
        {
            cout << "Mouvement pion impossible" << endl;
        }
    }

    else if (t[ld][cd] == -4 || t[ld][cd] == 4)
    {
        if (verifBishop(ld, cd, la, ca) == 2)
        {
        	cout << "la case contient une piece de la meme couleur" << endl;
		}
		else if (verifBishop(ld, cd, la, ca) == 3 || verifBishop(ld, cd, la, ca) == 0)
		{
			t[la][ca] = t[ld][cd];
        	t[ld][cd] = 0;
		}
               
        else
        {
            cout << "Mouvement Fou impossible" << endl;
        }
    }
    else if (t[ld][cd] == -3 || t[ld][cd] == 3)
    {
        if (verifRook(ld, cd, la, ca) == 2 || verifRook(ld, cd, la, ca) == 1)
        {
        	t[la][ca] = t[ld][cd];
            t[ld][cd] = 0;
    	}
    	else
        {
            cout << "Mouvement tour impossible" << endl;
        }
	}
	else if (t[ld][cd] == -2 || t[ld][cd] == 2) // Reine
{
    if (verifQueen(ld, cd, la, ca) == 2)
    {
        cout << "la case contient une piece de la meme couleur" << endl;
    }
    else if (verifQueen(ld, cd, la, ca) == 1 || verifQueen(ld, cd, la, ca) == 0)
    {
        t[la][ca] = t[ld][cd];
        t[ld][cd] = 0;
    }
    else
    {
        cout << "Mouvement Reine impossible" << endl;
    }
}
else if (t[ld][cd] == -1 || t[ld][cd] == 1) // Roi
{
    if (verifKing(ld, cd, la, ca))
    {
        t[la][ca] = t[ld][cd];
        t[ld][cd] = 0;
    }
    else
    {
        cout << "Mouvement roi impossible" << endl;
    }
}
	else
    {
        cout << "La piece n'est ni un cavalier ni un pion ni un fou ni une tour" << endl;
    }
}*/
void Echiquier::VerifRoi(vector<pos>ta,int x,int y){							//aussi pour le roi :
	int choix; 
	for(int i=0;i<ta.size();i++){
		cout<<i<<"---->"<<ta[i].x<<"   "<<ta[i].y<<endl; 	
	}
do{
	cout<<"donner le choix du deplacement : "; cin>>choix; 
}while(choix<0 || choix>ta.size()-1);
if(t[x][y]==6){
	t[ta[choix].x][ta[choix].y]=6; 
	t[x][y]=0; 
	if(ta[choix].x==0 && ta[choix].y==6)
		{
			t[0][5]=3; t[0][7]=0;
		}
		else if(ta[choix].x==0 && ta[choix].y==2){
			t[0][0]=0; t[0][3]=3;  
		}
		roquegrand=false;roque==false;
}else { 
	t[ta[choix].x][ta[choix].y]=-6; 
	t[x][y]=0; 
		if(ta[choix].x==7 && ta[choix].y==6)
		{
			t[7][5]=-3; t[7][7]=0;
		} 
		else if(ta[choix].x==7 && ta[choix].y==2){
			t[7][3]=-3; t[7][0]=0;	
		}
		roque2=false; roquegrand2=false;
}

}

void Echiquier::VerifReine(vector<pos>ta,int x,int y){							//enfin la reine : 
int choix; 
for(int i=0;i<ta.size();i++){
		cout<<i<<"---->"<<ta[i].x<<"   "<<ta[i].y<<endl; 	
	}
do{
	cout<<"donner le choix du deplacement : "; cin>>choix; 
}while(choix<0 || choix>ta.size()-1);
if(t[x][y]==5){
	t[ta[choix].x][ta[choix].y]=5; 
	t[x][y]=0; 
}else { 
	t[ta[choix].x][ta[choix].y]=-5; 
	t[x][y]=0; 
}
}
bool Echiquier::cherchercloue(vector<pos> t,int x,int y){
	
for (int i=0;i<t.size();i++){
	if(t[i].x==x && t[i].y==y)
		return true; 
}	
return false; 	
}


//// verifier Dragon :: 
void Echiquier::VerifDragon(vector<pos> ta, int x, int y) {
    // V�rifier le mouvement du Roi
    VerifRoi(ta, x, y);
    
    // V�rifier le mouvement du Fou
    VerifFou(ta, x, y);
    
    // V�rifier les captures "de loin"
    // Capture � gauche
    if (x > 0 && t[x-1][y] != 0) {
        pos capture = {x-1, y};
        ta.push_back(capture);
    }
    
    // Capture � droite
    if (x < 7 && t[x+1][y] != 0) {
        pos capture = {x+1, y};
        ta.push_back(capture);
    }
    
    // Capture en avant
    if (y > 0 && t[x][y-1] != 0) {
        pos capture = {x, y-1};
        ta.push_back(capture);
    }
    
    // Capture en arri�re
    if (y < 7 && t[x][y+1] != 0) {
        pos capture = {x, y+1};
        ta.push_back(capture);
    }
}
//---------------------------verifier la position de depart : 

void Echiquier::VerifDepart(){
	int x,y; 
	vector<pos> ta; 
do{
cout<<endl<<"donner la ligne de depart : "; cin>>x; 	
cout<<"donner la colonne de depart : "; cin>>y;     if(tj==1)ta=clouageblanc();
																else ta=clouagenoire(); 
																for(int i=0;i<ta.size();i++)
																	cout<<ta[i].x<<"   "<<ta[i].y<<endl;
																
}while(x<0 || x>7 || y<0 || y>7 || t[x][y]==0 || (tj==2 && t[x][y]>=0) || (tj==1 &&t[x][y]<=0) || (tj==1 && cherchercloue(ta,x,y)==true) || (tj==2 && cherchercloue(ta,x,y)==true)); 	//on accepte les position de tableau et chaque joueur doit choisir ces pieces : 
	
	if(t[x][y]==1 && t[x+1][y]!=0){				// je teste si c'est un pion et la case suivante en ligne n'est pas vide je teste si il a une piece en y+1 et y-1 a attraper sinon le pion est bloqu� : 
		int i=x+1,j=y+1; bool trouve=false; 
		while(i<8 && j<8 && trouve==false){
			if(t[i][j]<0){
				trouve=true; 
			}
			i=8;
		}
		if(trouve == false){
			j=y-1; i=x+1;
			while(i<8 && j>=0 && trouve==false){
			if(t[i][j]<0){
				trouve=true; 
			} i=8; 
			}
		}
		if(trouve==true)
			VerifArriv(x,y);
		else 
		VerifDepart();	
	}
	else if(t[x][y]==-1 && t[x-1][y]!=0){     // meme travaille pour l'autre joueur : 
			int i=x-1,j=y+1; bool trouve=false; 
		while(i>=0 && j<8 && trouve==false){
			if(t[i][j]>0){
				trouve=true; 
			}
			j=8;
		}
		if(trouve == false){
			j=y-1; 
			while(i>=0 && j>=0 && trouve==false){
			if(t[i][j]>0){
				trouve=true; 
			} j=-1;
			}
			}
			if(trouve==true)
			VerifArriv(x,y);
			else
			VerifDepart();
			}
	
	 if((tj==2 && t[x][y]==-1 && x==6 && t[x-2][y]==0) || (tj==1 && t[x][y]==1 && x==1 && t[x+2][y]==0)){ //juste pour informer le joueur que ce pion peut se deplacer de deux cases : (si il est en ligne 1 ou 6 sa depends de joueur) 
		cout<<"Ce pion peut se deplacer de deux cases ! "<<endl; VerifArriv(x,y); //on appelle la pos d'arv
	}
	else if (tj==2 && t[x][y]==-1 && t[x-1][y]==0 || tj==1 && t[x][y]==1 && t[x+1][y]==0 || tj==2 && t[x][y]==-1 && (t[x-1][y-1]>0 || t[x-1][y+1]>0 )||  tj==1 && t[x][y]==1 && (t[x+1][y+1]<0 || t[x+1][y-1]<0)){
		VerifArriv(x,y);					//le deplacement avec un ligne de plus si c'est =0 ou avec ligne +1 et colone +-1 si c'est unr piece de l'enmie . 
	}
	
	else if(t[x][y]==2 && tj==1 ){			//le cas de cavalier je traite pas ici si c'est possible de le deplacer je traite dans la position d'arriver si il est correcte sinon je demande qu'il change la piece :  
	 VerifArriv(x,y);
	}else if (t[x][y]==-2 && tj==2){
		VerifArriv(x,y); 
	}
	else if(t[x][y]==4 && tj==1 || (t[x][y]==-4 && tj==2)){  //le cas de fou posAposs retourne les positions possible 
	ta=posAposs(x,y); 
	if(ta.size()==0) 			//si le tableau est vide alors le fou ne peut pas se deplacer alors on fait une appelle recursive a la pos de depart: 
	VerifDepart(); 
	else 						//sinon on fait le mvt : 
	VerifFou(ta,x,y); 
	}
	else if (t[x][y]==3 && tj==1 || t[x][y]==-3 && tj==2){ 		//meme travaille pour les autre piece (tour roi reine ): 
		ta=posAposs(x,y); 
		if(ta.size()==0)
		VerifDepart(); 
		else VerifTour(ta,x,y); 
	}
	else if(t[x][y]==6 && tj==1 || t[x][y]==-6 && tj==2){ 		// le roi : 
	ta=posAposs(x,y);	
		if(ta.size()==0){
		VerifDepart(); }
		else VerifRoi(ta,x,y); 
	}
	else if(t[x][y]==5 && tj==1 || t[x][y]==-5 && tj==2){		//la reine : 
		ta=posAposs(x,y);	
		if(ta.size()==0){
		VerifDepart(); }
		else VerifReine(ta,x,y); 	
	}
}
void Echiquier::jouer()							//organise le tour de jeu et donne la possibilite de donner la pos de depart au joueur convenable . 
{
if (tj==2){
cout<<"c'est le tour du premier joueur : les Blancs !";
VerifDepart(); 
}else {
	cout<<"c'est le tour du deuxieme joueur : les Noirs !";
VerifDepart(); 
}
}

int Echiquier::roiexiste(){			//a chaque jeu je fais ce teste si le roi existe en cas d'echec :  
int indr; 
if(tj==1)
	indr=6;
else 
indr=-6; 
for(int i=0;i<8;i++){
for(int j=0;j<8;j++){
if(t[i][j]==indr){
	return 1; 
}	
}
}
return 0; 
}

int Echiquier::FinPartie(){			//fonction retourne 1 si le roi existe .
if(roiexiste()==0)
	return 0; 
else 
	return 1; 
}
void Echiquier::sauvegarder(){				//en cas de sauvegarde de plateau (pas encore implementer dans le programme) : 
ofstream file ("jeu.txt",ios::out);	  
if(file){
for (int i=0;i<8;i++){
	for(int j=0;j<8;j++){
		file<<t[i][j]<<"   "; 
	}
	file<<endl; 
}
file.close(); 	
}	
}
void Echiquier::charger(){					//charger une partie apartir d'un fichier texte (je le remplie manuellement) (je travaille a faire une sauvegarde au moment du jeu): 
ifstream file("jeu.txt",ios::in);  
if(!file){
	cout<<"Impossible d'ouvrir jeu.txt"<<endl;
	return;
}

int loaded[8][8];
for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
		if(!(file>>loaded[i][j])){
			cout<<"Format de sauvegarde invalide"<<endl;
			return;
		}
	}
}

for(int i=0;i<8;i++){
	for(int j=0;j<8;j++){
		t[i][j]=loaded[i][j]; 
	}
}
	file.close(); 
}
pos Echiquier::chercherroi(int roi){
	pos a; 
	for (int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(t[i][j]==roi)
				{
					a.x=i; a.y=j; 
					return a;  			
				}
		}
	}
	
}


vector<pos> Echiquier::clouagenoire(){
	pos roi,temp,place;
	roi = chercherroi(-6);
	vector<pos> cloue; cloue.clear();
int i=roi.x+1; int j=roi.y; 	int x,y;
	int cp=0; temp.x=-1; temp.y=-1; 
	while(i<8){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==3 || t[x][y]==5) && y==roi.y){
			temp.x=i; temp.y=j; 
			 i++; cp++;  
		}
		else if(t[i][j]<0){
			i++; cp++; 
		}
		else
			i++; 
		if(cp>1 || t[i][j]==3 || t[i][j]==5){
			i=8; 
		}
	}
	if(cp==1 && temp.x!=-1){
		cloue.push_back(temp);
	}
	i=roi.x-1; cp=0; temp.x=-1; temp.y=-1; 
	while(i>=0){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==3 || t[x][y]==5) && y==roi.y ){
			temp.x=i; temp.y=j; 
			 i--; cp++; 
		}
		else if(t[i][j]<0){
			i--; cp++; 
		}
		else
			i--;
		if(cp>1 || t[i][j]==3 || t[i][j]==5){
			i=-1; 
		} 
	}
	if(cp==1 && temp.x!=-1){
		cloue.push_back(temp);
		}
			
	i=roi.x; j=roi.y+1; cp=0; temp.x=-1; temp.y=-1; 
	while(j<8){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==3 || t[x][y]==5) && x==roi.x){
			temp.x=i; temp.y=j; 
			cloue.push_back(temp); j=8; 
		}
		else
			j++; 		
	}
	j=roi.y-1;
	while(j>=0){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==3 || t[x][y]==5) && x==roi.x){
			temp.x=i; temp.y=j; 
			cp++; j--; 
		}
		else if(t[i][j]<0){
			j--; cp++; 
		}
		else
			j--;
			if(cp>1 || t[i][j]==3 || t[i][j]==5){
			j=-1; 
		} 	
	}
	if(cp==1 && temp.x!=-1){
		cloue.push_back(temp);
		}
	i=roi.x+1; j=roi.y+1; cp=0; temp.x=-1; temp.y=-1;
	while(i<8 && j<8){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==4 || t[x][y]==5) && y>roi.y){
			temp.x=i; temp.y=j; 
			 j++; cp++; i++;  
		}
		else if(t[i][j]<0){
			j++; cp++; i++;  
		}
		else{
			i++; j++;
		}
		if(cp>1 || t[i][j]==4 || t[i][j]==5){
			j=8; 
		}
	}
	if(cp==1 && temp.x!=-1){
		cloue.push_back(temp);
		}
		
	j=roi.y-1; i=roi.x+1; cp=0; temp.x=-1; temp.y=-1;
	while(i<8 && j>=0){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==4 || t[x][y]==5) && y<roi.y){
			temp.x=i; temp.y=j; 
			cp++; i++; j--;  
		}
		else if(t[i][j]<0){
			j--; cp++; i++;  
		}
		else{
			i++; j--;
		}
		if(cp>1 || t[i][j]==4 || t[i][j]==5){
			i=8; 
		}
	}
	if(cp==1 && temp.x!=-1){
		cloue.push_back(temp);
		}
		
	i=roi.x-1; j=roi.y-1; cp=0; temp.x=-1; temp.y=-1;
	while(i>=0 && j>=0){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==4 || t[x][y]==5) && y<roi.y){
			temp.x=i; temp.y=j; 
			cp++; j--; i--; 
		}
		else if(t[i][j]<0){
			j--; cp++; i--;  
		}
		else{
			i--; j--;
		}
		if(cp>1 || t[i][j]==4 || t[i][j]==5){
			i=-1; 
		}
	}
	if(cp==1 && temp.x!=-1){
		cloue.push_back(temp);
		}
	i=roi.x-1; j=roi.y+1; cp=0; temp.x=-1; temp.y=-1;
	while(i>=0 && j<8){
		if(t[i][j]<0 && echecnoir(x,y,i,j)==1 && (t[x][y]==4 || t[x][y]==5) && y>roi.y){
			temp.x=i; temp.y=j; 
			cp++; i--; j++;
		}
		else if(t[i][j]<0){
			j++; cp++; i--;  
		}
		else{
			i--; j++;
		}
		if(cp>1 || t[i][j]==4 || t[i][j]==5){
			i=-1; 
		}
	}
	if(cp==1 && temp.x!=-1){
		cloue.push_back(temp);
		}
	return cloue; 
}
vector<pos> Echiquier::clouageblanc(){
	pos roi,temp,place; temp.x=-1; temp.y=-1; int cp=0;
	roi = chercherroi(6);
	vector<pos> cloue; 
int i=roi.x+1; int j=roi.y; 	int x,y;
	while(i<8){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-3 || t[x][y]==-5) && y==roi.y){
			temp.x=i; temp.y=j; 
			 i++; cp++;
		}
		 else if(t[i][j]>0)
				{
					cp++; i++; 
				}
		else
			i++; 
		if(cp>1 || t[i][j]==-3 || t[i][j]==-5)
			i=8;
	}
	if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
		}
	i=roi.x-1; temp.x=-1; temp.y=-1; cp=0;
	while(i>=0){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-3 || t[x][y]==-5) && y==roi.y ){
			temp.x=i; temp.y=j; 
			 i--; 
		}
		else if(t[i][j]>0)
				{
					cp++; i--; 
				}
		else
			i--; 
		if(cp>1 || t[i][j]==-3 || t[i][j]==-5)
			i=-1;		
	}
	if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
		}	
	i=roi.x; j=roi.y+1; cp=0; temp.x=-1; temp.y=-1; 
	while(j<8){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-3 || t[x][y]==-5) && x==roi.x){
			temp.x=i; temp.y=j; 
			j++; cp++;  
		}else if(t[i][j]>0)
				{
					cp++; j++; 
				}
		else
			j++; 		
		if(cp>1 || t[i][j]==-3 || t[i][j]==-5)
			j=8;	
	}
	if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
	}
	j=roi.y-1; cp=0; temp.x=-1; temp.y=-1;
	while(j>=0){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-3 || t[x][y]==-5) && x==roi.x){
			temp.x=i; temp.y=j; 
			j--; cp++; 
		}
		else if(t[i][j]>0){
			cp++; 
		}
		else
			j--;
		if(cp>1 || t[i][j]==-3 || t[i][j]==-5)
			j=-1;
	}
	if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
	}
	i=roi.x+1; j=roi.y+1; temp.x=-1; temp.y=-1; cp=0; 
	while(i<8 && j<8){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-4 || t[x][y]==-5) && y>roi.y ){
			temp.x=i; temp.y=j; 
			 j++; i++; cp++;
		}
		else if(t[i][j]>0){
			cp++; i++;j++;
		}
		else{ 
			i++; j++;
		}
		if(cp>1 || t[i][j]==-4 || t[i][j]==-5)
				j=8;
	}
	if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
	}
	j=roi.y-1; temp.x=-1; temp.y=-1; cp=0;
	while(i<8 && j>=0){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-4 || t[x][y]==-5) && y<roi.y){
			temp.x=i; temp.y=j; 
			 i++;j--; cp++;  
		}
		else if(t[i][j]>0){
			cp++; i++;j--;
		}
		else{ 
			i++; j--;
		}
		if(cp>1 || t[i][j]==-4 || t[i][j]==-5)
				j=-1;
		
	}
	if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
	}
	i=roi.x-1; j=roi.y-1; temp.x=-1; temp.y=-1; cp=0;
	while(i>=0 && j>=0){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-4 || t[x][y]==-5) && y<roi.y){
			temp.x=i; temp.y=j; 
			 j--; i--;  cp++; 
		}
		else if(t[i][j]>0){
			cp++; j--;i--;
		}
		else{
			i--; j--;
		}
		if(cp>1 || t[i][j]==-4 || t[i][j]==-5)
				j=-1;
	}if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
	}
	i=roi.x-1; j=roi.y+1; temp.x=-1; temp.y=-1; cp=0;
	while(i>=0 && j<8){
		if(t[i][j]>0 && echecblanc(x,y,i,j)==1 && (t[x][y]==-4 || t[x][y]==-5) && y>roi.y){
			temp.x=i; temp.y=j; 
			cp++; j++;i--; 
		}else if(t[i][j]>0){
			cp++; i--; j++;
		}
		else{
			i--; j++;
		}
		
		if(cp>1 || t[i][j]==-4 || t[i][j]==-5)
				j=-1;
	}if(temp.x!=-1 && cp==1){
		cloue.push_back(temp);
	}
	return cloue; 
}
bool Echiquier::echec_et_mat(){
	int x,y; 
if (tj==1){
		pos roi=chercherroi(6);
	if(echecblanc(x,y,roi.x,roi.y)==0)
			return false; 
		if(roi.x+1<8 && (t[roi.x+1][roi.y]==0 || t[roi.x+1][roi.y]<0))
			if (echecblanc(x,y,roi.x+1,roi.y)==0)
				return false; 
		if(roi.x-1>=0 && (t[roi.x-1][roi.y]==0 || t[roi.x-1][roi.y]<0))
			if(echecblanc(x,y,roi.x-1,roi.y)==0)
				return false;
		if(roi.x+1<8 && roi.y+1<8 && (t[roi.x+1][roi.y+1]==0 || t[roi.x+1][roi.y+1]<0))
			if(echecblanc(x,y,roi.x+1,roi.y+1)==0)
				return false; 
		if(roi.x+1<8 && roi.y-1>=0 && (t[roi.x+1][roi.y-1]==0 || t[roi.x+1][roi.y-1]<0 ))
			if(echecblanc(x,y,roi.x+1,roi.y-1)==0)
				return false; 
		if(roi.x-1>=0 && roi.y+1<8 && (t[roi.x-1][roi.y+1]==0 || t[roi.x-1][roi.y+1]<0))
			if(echecblanc(x,y,roi.x-1,roi.y+1)==0)
				return false; 
		if(roi.x-1>=0 && roi.y-1>=0 && (t[roi.x-1][roi.y-1]==0 || t[roi.x-1][roi.y-1]<0))
			if(echecblanc(x,y,roi.x-1,roi.y-1)==0)
				return false; 
		if(roi.y+1<8 && (t[roi.x][roi.y+1]==0 || t[roi.x][roi.y+1]<0))
			if(echecblanc(x,y,roi.x,roi.y+1 )==0)
				return false; 
		if(roi.y-1>=0 && (t[roi.x][roi.y-1]==0 || t[roi.x][roi.y-1]<0))
			if(echecblanc(x,y,roi.x,roi.y-1)==0)
				return false; 
	}
	else {
		pos roi=chercherroi(-6);
		if(echecnoir(x,y,roi.x,roi.y)==0)
			return false; 
		if(roi.x+1<8 && (t[roi.x+1][roi.y]==0 || t[roi.x+1][roi.y]>0))
			if (echecnoir(x,y,roi.x+1,roi.y))
				return false; 
		if(roi.x-1>=0 && (t[roi.x-1][roi.y]==0 || t[roi.x+1][roi.y]>0))
			if(echecnoir(x,y,roi.x-1,roi.y)==0)
				return false;
		if(roi.x+1<8 && roi.y+1<8 &&( t[roi.x+1][roi.y+1]==0 || t[roi.x+1][roi.y+1]>0))
			if(echecnoir(x,y,roi.x+1,roi.y+1)==0)
				return false; 
		if(roi.x+1<8 && roi.y-1>=0 && (t[roi.x+1][roi.y-1]==0 || t[roi.x+1][roi.y-1]>0))
			if(echecnoir(x,y,roi.x+1,roi.y-1)==0)
				return false; 
		if(roi.x-1>=0 && roi.y+1<8 && (t[roi.x-1][roi.y+1]==0 || t[roi.x+1][roi.y+1]>0))
			if(echecnoir(x,y,roi.x-1,roi.y+1)==0)
				return false; 
		if(roi.x-1>=0 && roi.y-1>=0 && (t[roi.x-1][roi.y-1]==0 || t[roi.x+1][roi.y-1]>0))
			if(echecnoir(x,y,roi.x-1,roi.y-1)==0)
				return false; 
		if(roi.y+1<8 && (t[roi.x][roi.y+1]==0 || t[roi.x+1][roi.y+1]>0)){
			if(echecnoir(x,y,roi.x,roi.y+1)==0)
				return false; 
		}
		if(roi.y-1>=0 && (t[roi.x][roi.y-1]==0 || t[roi.x+1][roi.y-1]>0))
			if(echecnoir(x,y,roi.x,roi.y-1)==0)
				return false; 
	}
	return true; 
}

void Echiquier::setroque(bool ro){
	roque=ro; 
} 
void Echiquier::setgrandroque(bool ro){
		roquegrand=ro; 
		}
bool Echiquier::getroque(){
		return roque; 
		} 
bool Echiquier::getgrandroque(){
		return roquegrand; 
		}
void Echiquier::setroque2(bool ro)
		{
		roque2=ro; 
		 } 
void Echiquier::setgrandroque2(bool ro){
		roquegrand2=ro; 
		}
bool Echiquier::getroque2(){
		return roque2; 
		} 
bool Echiquier::getgrandroque2(){
	return roquegrand2; 
		}	
void Echiquier::setEnPassant(pos a){
		EnPassant=a; 
		}
void Echiquier::setEnPassant2(pos a){
	EnPassant2=a; 
	}
void Echiquier::settj(int j){
	tj=j;
		} 
int Echiquier::gettj(){
	return tj; 
		}
Echiquier::~Echiquier(){
}
