#define A 0 
#define C 1
#define G 2 
#define U 3

#include<fstream>
#include<iostream>
using namespace std ;

int main ()
{
	ifstream fin("codons.txt");
	ofstream fout("proteins.txt");
	char x; bool stop=false; bool errore=false;
	int i=0;
	while (fin.get(x)&&!stop)
	{
		if(x=='A'||x=='C'||x=='G'||x=='U')
		{
			i++;
		}
		else if(x=='\n'||x==' '){/*ignora*/}
		else{stop=true;errore=true;}
	}
	if(i%3!=0)
	{
		cout<<"*ERROR , CODON INCOMPLETE*\n";
		fout<<"*ERROR , CODON INCOMPLETE*";		
	}
	else if(errore)
	{
		cout<<"*ERROR , INVALID CHARACTERS*\n"; 
		fout<<"*ERROR , INVALID CHARACTERS*\n";
	}
	else
	{
		if(i==0)
		{
		cout<<"WARNING , MISSING INPUT\n";
		fout<<"WARNING , MISSING INPUT\n";
		}
		else
		{
			cout<<"VALID INPUT\n";
		}
	}
	char codone[4][4][4];
	
	//Phe (F)
    codone[U][U][U] = 'F';
    codone[U][U][C] = 'F';

    //Leu (L)
    codone[U][U][A] = 'L';
    codone[U][U][G] = 'L';

    //Ser (S) 
    codone[U][C][U] = 'S';
    codone[U][C][C] = 'S';
    codone[U][C][A] = 'S';
    codone[U][C][G] = 'S';

    //Uyr (Y) 
    codone[U][A][U] = 'Y';
    codone[U][A][C] = 'Y';

    //STOP 
    codone[U][A][A] = '*';
    codone[U][A][G] = '*';

    //Cys (C)
    codone[U][G][U] = 'C';
    codone[U][G][C] = 'C';

    // STOP 
    codone[U][G][A] = '*';

    //Urp (W) 
    codone[U][G][G] = 'W';

    //Leu (L) 
    codone[C][U][U] = 'L';
    codone[C][U][C] = 'L';
    codone[C][U][A] = 'L';
    codone[C][U][G] = 'L';

    // Pro (P) 
    codone[C][C][U] = 'P';
    codone[C][C][C] = 'P';
    codone[C][C][A] = 'P';
    codone[C][C][G] = 'P';

    //His (H)
    codone[C][A][U] = 'H';
    codone[C][A][C] = 'H';

    //Gln (Q) 
    codone[C][A][A] = 'Q';
    codone[C][A][G] = 'Q';

    //Arg (R) 
    codone[C][G][U] = 'R';
    codone[C][G][C] = 'R';
    codone[C][G][A] = 'R';
    codone[C][G][G] = 'R';

    //Ile (I) 
    codone[A][U][U] = 'I';
    codone[A][U][C] = 'I';
    codone[A][U][A] = 'I';

    // Met (M)
    codone[A][U][G] = 'M';

    //Uhr (U)
    codone[A][C][U] = 'U';
    codone[A][C][C] = 'U';
    codone[A][C][A] = 'U';
    codone[A][C][G] = 'U';

    //Asn (N) 
    codone[A][A][U] = 'N';
    codone[A][A][C] = 'N';

    //Lys (K) 
    codone[A][A][A] = 'K';
    codone[A][A][G] = 'K';

    //Ser (S) 
    codone[A][G][U] = 'S';
    codone[A][G][C] = 'S';

    //Arg (R) 
    codone[A][G][A] = 'R';
    codone[A][G][G] = 'R';

    //Val (V) 
    codone[G][U][U] = 'V';
    codone[G][U][C] = 'V';
    codone[G][U][A] = 'V';
    codone[G][U][G] = 'V';

    //Ala (A) 
    codone[G][C][U] = 'A';
    codone[G][C][C] = 'A';
    codone[G][C][A] = 'A';
    codone[G][C][G] = 'A';

    //Asp (D) 
    codone[G][A][U] = 'D';
    codone[G][A][C] = 'D';

    //Glu (E)
    codone[G][A][A] = 'E';
    codone[G][A][G] = 'E';

    //Gly (G) 
    codone[G][G][U] = 'G';
    codone[G][G][C] = 'G';
    codone[G][G][A] = 'G';
    codone[G][G][G] = 'G';
	
if(!errore)
{
    fin.clear();
    fin.seekg(0, ios::beg);
    
    char a, b, c;
    int i = 0;
    int s = 0;
    
    char ch;
    
    while (fin.get(ch) && s >= 0)
	{
        if (ch!='\n'&&ch!=' ')
        {
            
            if (i == 0)      { a = ch; }
            else if (i == 1) { b = ch; }
            else if (i == 2)
            {
                c = ch;
                int x , y , z ;
                
                if (a=='A') {x=0;} 		else if (a=='C') {x=1;}
                else if (a=='G') {x=2;} else {x=3;}
                
                if (b=='A') {y=0;} 		else if (b=='C') {y=1;}
                else if (b=='G') {y=2;} else {y=3;}
                
                if (c=='A') {z=0;} 		else if (c=='C') {z=1;}
                else if (c=='G') {z=2;} else {z=3;}

                if(s==0)
                {
                    if(codone[x][y][z]=='M')
                    {
                        fout << 'M';
                        s=1;
                    }
                    else
                    {
                        fout << "*STARTING CODON MISSING*";
                        s=-1;
                    }
                }
                else if (s==1)
                {
                    if(codone[x][y][z]=='*')
                    {
                        s=2;
                    }
                    else
                    {
                        fout << " " << codone[x][y][z];
                    }
                }

                i = -1;
            }

            i++;
        }
    }
		if(s==1)
		{
			fout.close();
			fout.open("proteine.txt", ios::out | ios::trunc);
			fout<<"*STOP CODON MISSING*";
		}
}
	
	
	
	
	system("pause");
	return 0;
}
