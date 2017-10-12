//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <string.h>
#include <fstream>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"


TForm1 *Form1;
TImage *lastPressed;



enum {gray, green, red};
struct myKey
{
char val;
TImage *obj;

};

class ButtonQuee{
public:
        bool is_empty(){ return (counter == 0) ? true : false; };

        void push( TImage *button){Buffor[counter] = button; counter++; }

        TImage* pop( ){  TImage *first = Buffor[0];
                         this->MoveDownAll();
                         return first; }

        void MoveDownAll(){ int temp_count = 0;


                             while(temp_count < counter){
                             Buffor[temp_count] = Buffor[temp_count+1];
                             temp_count++;
                             }
                             counter--;
                              }

private:
 TImage* Buffor[100];
 int counter;
};

class KeyMapper
{

public:

String GetColorPath(String key, int color){

String ret;
switch (color) {

 case red: { ret= "imgr/"; break;};
 case green: {ret = "imjj/"; break;};
 case gray:{ ret = "img/"; break;};

 }

 if (key.Length() > 1){
 // switch (key){
 //case "sp":
 //{
 ret+= key;
 //};


 //}


 }else{

 char ch = key.c_str()[0];
 int asci = (int)ch;

 switch (asci) {



 case 32: { ret+= "sp"; break; };
 case 33: { ret+= "p1"; break; };
 case 34: { ret+= "paz"; break; };
 case 35: { ret+= "p3"; break; };
 case 36: { ret+= "p4"; break; };
 case 37: { ret+= "p5"; break; };
 case 38: { ret+= "p7"; break; };
 case 39: { ret+= "paz"; break; };
 case 40: { ret+= "p9"; break; };
 case 41: { ret+= "p0"; break; };
 case 42: { ret+= "p8"; break; };
 case 43: { ret+= "pl"; break; };
 case 44: { ret+= "prz"; break; };
 case 45: { ret+= "min"; break; };
 case 46: { ret+= "kr"; break; };
 case 47: { ret+= "pyt"; break; };
 case 48: { ret+= "p0"; break; };
 case 49: { ret+= "p1"; break; };
 case 50: { ret+= "p2"; break; };
 case 51: { ret+= "p3"; break; };
 case 52: { ret+= "p4"; break; };
 case 53: { ret+= "p5"; break; };
 case 54: { ret+= "p6"; break; };
 case 55: { ret+= "p7"; break; };
 case 56: { ret+= "p8"; break; };
 case 57: { ret+= "p9"; break; };
 case 58: { ret+= "sr"; break; };
 case 59: { ret+= "sr"; break; };
 case 60: { ret+= "prz"; break; };
 case 61: { ret+= "p9"; break; };
 case 62: { ret+= "kr"; break; };
 case 63: { ret+= "pyt"; break; };



 case 64: { ret+= "p2"; break; };
 case 65: { ret+= "a"; break; };
 case 66: { ret+= "b"; break; };
 case 67: { ret+= "c"; break; };
 case 68: { ret+= "d"; break; };
 case 69: { ret+= "e"; break; };
 case 70: { ret+= "f"; break; };
 case 71: { ret+= "g"; break; };
 case 72: { ret+= "h"; break; };
 case 73: { ret+= "i"; break; };
 case 74: { ret+= "j"; break; };
 case 75: { ret+= "k"; break; };
 case 76: { ret+= "l"; break; };
 case 77: { ret+= "m"; break; };
 case 78: { ret+= "n"; break; };
 case 79: { ret+= "o"; break; };
 case 80: { ret+= "p"; break; };
 case 81: { ret+= "q"; break; };
 case 82: { ret+= "r"; break; };
 case 83: { ret+= "s"; break; };
 case 84: { ret+= "t"; break; };
 case 85: { ret+= "u"; break; };
 case 86: { ret+= "v"; break; };
 case 87: { ret+= "w"; break; };
 case 88: { ret+= "x"; break; };
 case 89: { ret+= "y"; break; };
 case 90: { ret+= "z"; break; };
 case 91: { ret+= "nar"; break; };
 case 92: { ret+= "backs"; break; };
 case 93: { ret+= "nal"; break; };
 case 94: { ret+= "p6"; break; };
 case 95: { ret+= "min"; break; };
 case 96: { ret+= "prz"; break; };

 case 123: { ret+= "nar"; break; };
 case 124: { ret+= "backs"; break; };
 case 125: { ret+= "nal"; break; };
 case 126: { ret+= "tl"; break; };
  case 8: { ret+= "bs"; break; };
 case 13: { ret+= "enter"; break; };

/* case 164: { ret+= "a"; break; }; //¥
 case 165: { ret+= "a"; break; };   //¹
 case 227: { ret+= "n"; break; };   //Ñ
 case 228: { ret+= "n"; break; };   //ñ
 case 151: { ret+= "s"; break; };   //S
 case 152: { ret+= "s"; break; };   //s
 case 168: { ret+= "e"; break; };   //Ê
 case 169: { ret+= "e"; break; };   //ê
 case 136: { ret+= "l"; break; };   //³
 case 134: { ret+= "c"; break; };   //c
 case 143: { ret+= "c"; break; };   //C
 case 171: { ret+= "z"; break; };   //Ÿ
 case 169: { ret+= "e"; break; };   //ê
 case 168: { ret+= "e"; break; };   //Ê
 case 141: { ret+= "z"; break; };   //
 case 189: { ret+= "z"; break; };   //¯
 case 162: { ret+= "o"; break; };   //ó
 case 190: { ret+= "z"; break; };   //¿
 */





 //case green: {ret = "imjj/";}
 //case gray:{ ret = "img/";}
 default: ret+= key;
 }  };




ret+= ".bmp";

return ret;
}

KeyMapper(){
 /*this->addKey('¹', Form1->a);
 this->addKey('¥', Form1->a);
 this->addKey('ñ', Form1->n);
 this->addKey('Ñ', Form1->n);
 //this->addKey('Œ', Form1->s);
 //this->addKey('œ', Form1->s);
 this->addKey('¿', Form1->z);
 this->addKey('¯', Form1->z);
 this->addKey('Ÿ', Form1->z);
 this->addKey('', Form1->z);
 this->addKey('ó', Form1->o);
 this->addKey('Ó', Form1->o);
 this->addKey('ê', Form1->e);
 this->addKey('Ê', Form1->e);
 this->addKey('³', Form1->l);
 this->addKey('£', Form1->l);
 this->addKey('ê', Form1->e);
 this->addKey('Ê', Form1->e);
 //this->addKey('æ', Form1->c);
 //this->addKey('Æ', Form1->c);
 */
 this->addKey('q', Form1->q);
 this->addKey('w', Form1->w);
 this->addKey('e', Form1->e);
 this->addKey('r', Form1->r);
 this->addKey('t', Form1->t);
 this->addKey('y', Form1->y);
 this->addKey('u', Form1->u);
 this->addKey('i', Form1->i);
 this->addKey('o', Form1->o);
 this->addKey('p', Form1->p);
 this->addKey('a', Form1->a);
 this->addKey('s', Form1->s);
 this->addKey('d', Form1->d);
 this->addKey('f', Form1->f);
 this->addKey('g', Form1->g);
 this->addKey('h', Form1->h);
 this->addKey('j', Form1->j);
 this->addKey('k', Form1->k);
 this->addKey('l', Form1->l);
 this->addKey('z', Form1->z);
 this->addKey('x', Form1->x);
 this->addKey('c', Form1->c);
 this->addKey('v', Form1->v);
 this->addKey('b', Form1->b);
 this->addKey('n', Form1->n);
 this->addKey('m', Form1->m);
 this->addKey('Q', Form1->q);
 this->addKey('W', Form1->w);
 this->addKey('E', Form1->e);
 this->addKey('R', Form1->r);
 this->addKey('T', Form1->t);
 this->addKey('Y', Form1->y);
 this->addKey('U', Form1->u);
 this->addKey('I', Form1->i);
 this->addKey('O', Form1->o);
 this->addKey('P', Form1->p);
 this->addKey('A', Form1->a);
 this->addKey('S', Form1->s);
 this->addKey('D', Form1->d);
 this->addKey('F', Form1->f);
 this->addKey('G', Form1->g);
 this->addKey('H', Form1->h);
 this->addKey('J', Form1->j);
 this->addKey('K', Form1->k);
 this->addKey('L', Form1->l);
 this->addKey('Z', Form1->z);
 this->addKey('X', Form1->x);
 this->addKey('C', Form1->c);
 this->addKey('V', Form1->v);
 this->addKey('B', Form1->b);
 this->addKey('N', Form1->n);
 this->addKey('M', Form1->m);
 this->addKey('.', Form1->kr);
 this->addKey(',', Form1->prz);
 this->addKey('?', Form1->pyt);
 this->addKey('~', Form1->tl);
 this->addKey('0', Form1->p0);
 this->addKey('1', Form1->p1);
 this->addKey('2', Form1->p2);
 this->addKey('3', Form1->p3);
 this->addKey('4', Form1->p4);
 this->addKey('5', Form1->p5);
 this->addKey('6', Form1->p6);
 this->addKey('7', Form1->p7);
 this->addKey('9', Form1->p9);
 this->addKey('+', Form1->pl);
 this->addKey('-', Form1->min);
 this->addKey('$', Form1->p4);
 this->addKey('@', Form1->p2);
 this->addKey('!', Form1->p1);
 this->addKey('#', Form1->p3);
 this->addKey('%', Form1->p5);
 this->addKey('^', Form1->p6);
 this->addKey('&', Form1->p7);
 this->addKey('*', Form1->p8);
this->addKey('(', Form1->p9);
this->addKey(')', Form1->p0);
this->addKey('_', Form1->min);
this->addKey('=', Form1->pl);
 this->addKey('[', Form1->nar);
 this->addKey(']', Form1->nal);
 this->addKey('{', Form1->nar);
 this->addKey('}', Form1->nal);
 this->addKey(':', Form1->sr);
 this->addKey(';', Form1->sr);
 this->addKey('"', Form1->paz);
 this->addKey('/', Form1->pyt);
 this->addKey('>', Form1->kr);
 this->addKey('<', Form1->prz);
 this->addKey('\\', Form1->backs);
 this->addKey('|', Form1->backs);
 this->addKey(' ', Form1->sp);
 this->addKey('\b', Form1->bs);
 this->addKey('\r', Form1->enter);



}


void addKey(char key, TImage *obj){
        int place = (int)key;

        Tab[place].obj = obj;             //
        Tab[place].val = key;             //

}

TImage* getTImage(char key ){
 int place = (int)key;

 return Tab[place].obj;

}


myKey Tab[1000];

};

typedef String linia;

class TextContent
{

public:
 bool isFinished(int x, int y)
 {     if( y == this->max_line-1 && x >= this->tab[y-1].Length() ){
        return true;
        }else { return false;};
 }

int max_line;

void CaretControlBefore(TMemo *memo, char &Key ){

TPoint pt = memo->CaretPos;

if ( memo->CaretPos.y == 0 || ( memo->CaretPos.y % 2==0)){

       pt.y++;

 if (pt.x > this->GetLine(pt.y).Length()-1 ) pt.x = this->GetLine(pt.y).Length()-1;

  memo->CaretPos = pt;
}

if (pt.x > this->GetLine(pt.y-1).Length()-1 ) {pt.x = 0; pt.y+=2;};
   memo->CaretPos = pt;

if (Key != NULL && Key == '\b' && pt.x == 0){
Key = NULL;
//pt.y =
memo->CaretPos = pt;
};

}

void CaretControlAfter(TMemo *memo){

TPoint pt = memo->CaretPos;

if (pt.y > 0 && pt.x > this->GetLine(pt.y-1).Length()-1 ) {pt.x = 0; pt.y+=2;};
   memo->CaretPos = pt;
}

bool is_Equal( char a, char b);

char get_CharOnPos( int x, int y){
        String line = tab[y];


 String ret1 =  line.SubString(x,1);    //
 char ret    =  ret1.c_str()[0];          //

       // isFinished(pt.x, pt.y);

        return ret;


};


TextContent(){
tab = new linia[100];
};
linia *tab;

String GetLine(int x)
{
 return tab[x];
}

String getAllLines(){
String all;
for(int i = 0; i<100;i++)
 {all = all + tab[i];}
 return all;
}



void SetTempCont(String y)
{
   int i = 0, last;
   int dlugosc = y.Length();
   int window_lenght =   56;

   //y.SubString(0,50);
   this->max_line = 0;
   while(dlugosc>0)

   {

   if(dlugosc < window_lenght){
   tab[i++] = y.SubString(0,dlugosc) ;
   y=y.SubString(window_lenght+1,dlugosc);
   dlugosc = 0;
   }else{
   tab[i++] = y.SubString(0,window_lenght) ;
   y=y.SubString(window_lenght+1,dlugosc-window_lenght+2);
   dlugosc = y.Length();

   };

  // tab[i++]="\r\n";
   tab[i++]="\r\n\r\n";
   }
   max_line= i;

}

void setLine(int row, String line){
tab[row] = line;
}

};

bool TextContent::is_Equal( char a, char b){
        return ( a == b) ? true : false;   };




TextContent *t1;

KeyMapper *mapper;
ButtonQuee *bt_que;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::FormCreate(TObject *Sender)
{


Timer3->Enabled = false;
t1 = new TextContent();

mapper = new KeyMapper( );
bt_que = new ButtonQuee();


//t1->SetTempCont("*&qwertyuiopasdfghjklzxcvbnm qwertyuiopasdfghjklzxcvbnm qwertyuiopasdfghjklzxcvbnm");
//pole->Text=t1->getAllLines();

//t1->CaretControl(this->pole);
tl->Picture->LoadFromFile("img/tl.bmp");

 p1->Picture->LoadFromFile("img/p1.bmp");
p2->Picture->LoadFromFile("img/p2.bmp");
 p3->Picture->LoadFromFile("img/p3.bmp");
 p4->Picture->LoadFromFile("img/p4.bmp");
 p5->Picture->LoadFromFile("img/p5.bmp");
 p6->Picture->LoadFromFile("img/p6.bmp");
 p7->Picture->LoadFromFile("img/p7.bmp");
 p8->Picture->LoadFromFile("img/p8.bmp");
 p9->Picture->LoadFromFile("img/p9.bmp");
 p0->Picture->LoadFromFile("img/0p.bmp");
 bs->Picture->LoadFromFile("img/bs.bmp");
 pl->Picture->LoadFromFile("img/pl.bmp");
 min->Picture->LoadFromFile("img/min.bmp");
 sp->Picture->LoadFromFile("img/sp.bmp");
  tab->Picture->LoadFromFile("img/tab.bmp");
  shiftr->Picture->LoadFromFile("img/shiftr.bmp");
  shiftl->Picture->LoadFromFile("img/shiftl.bmp");
  enter->Picture->LoadFromFile("img/enter.bmp");
 cl->Picture->LoadFromFile("img/cl.bmp");
ctrll->Picture->LoadFromFile("img/ctrll.bmp");
ctrlr->Picture->LoadFromFile("img/ctrlr.bmp");
altl->Picture->LoadFromFile("img/altl.bmp");
altr->Picture->LoadFromFile("img/altr.bmp");
backs->Picture->LoadFromFile("img/backs.bmp");
q->Picture->LoadFromFile("img/q.bmp");
w->Picture->LoadFromFile("img/w.bmp");
e->Picture->LoadFromFile("img/e.bmp");
r->Picture->LoadFromFile("img/r.bmp");
t->Picture->LoadFromFile("img/t.bmp");
y->Picture->LoadFromFile("img/y.bmp");
u->Picture->LoadFromFile("img/u.bmp");
i->Picture->LoadFromFile("img/i.bmp");
o->Picture->LoadFromFile("img/o.bmp");
p->Picture->LoadFromFile("img/p.bmp");
a->Picture->LoadFromFile("img/a.bmp");
s->Picture->LoadFromFile("img/s.bmp");
d->Picture->LoadFromFile("img/d.bmp");
f->Picture->LoadFromFile("img/f.bmp");
g->Picture->LoadFromFile("img/g.bmp");
h->Picture->LoadFromFile("img/h.bmp");
j->Picture->LoadFromFile("img/j.bmp");
k->Picture->LoadFromFile("img/k.bmp");
l->Picture->LoadFromFile("img/l.bmp");
z->Picture->LoadFromFile("img/z.bmp");
x->Picture->LoadFromFile("img/x.bmp");
c->Picture->LoadFromFile("img/c.bmp");
v->Picture->LoadFromFile("img/v.bmp");
b->Picture->LoadFromFile("img/b.bmp");
n->Picture->LoadFromFile("img/n.bmp");
m->Picture->LoadFromFile("img/m.bmp");
pyt->Picture->LoadFromFile("img/pyt.bmp");
nar->Picture->LoadFromFile("img/nar.bmp");
nal->Picture->LoadFromFile("img/nal.bmp");
paz->Picture->LoadFromFile("img/paz.bmp");
sr->Picture->LoadFromFile("img/sr.bmp");
prz->Picture->LoadFromFile("img/prz.bmp");
kr->Picture->LoadFromFile("img/kr.bmp");

}//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
TImage *img;

while (bt_que->is_empty() == false ){


  img = bt_que->pop();
                                                            //.c_str()[0]
  img->Picture->LoadFromFile( mapper->GetColorPath(img->Name, gray ) );


};

  Timer1->Enabled = true;
 }
//---------------------------------------------------------------------------

    int dobrze=0;
    int zle;
    char last_char;
void __fastcall TForm1::poleKeyPress(TObject *Sender, char &Key)
{

TImage *pressed;
last_char = Key;
if (Key != 27){
if (Key == '\r' ) {Key = ' ';};

        pressed = mapper->getTImage(Key);
        bt_que->push(pressed);

 char ori_char = t1->get_CharOnPos(  this->pole->CaretPos.x+1,  this->pole->CaretPos.y-1 );

 if ( t1->is_Equal(ori_char, Key) == true){
 dobrze++ ;
 //char *w={"kmwakd"};
// Application->MessageBox(w, "Koniec", MB_OK);


        pressed->Picture->LoadFromFile( mapper->GetColorPath(Key,green) );

 }else {
         pressed->Picture->LoadFromFile( mapper->GetColorPath(Key,red) );
             zle++;
        };

        String actual_line = t1->GetLine(this->pole->CaretPos.y);
        actual_line+=Key;
        t1->setLine(this->pole->CaretPos.y, actual_line);


t1->CaretControlBefore(pole, Key);

String last = pressed->Name;


Timer1->Enabled = true;

};
 }


void __fastcall TForm1::OpenDialog1Close(TObject *Sender)
{
std::fstream plik;

String s = OpenDialog1->FileName;//e = ''.

//plik.open(
//, std::ios::in);

bool good();
bool is_open();
if (plik.good()== true)
{
std::cout<<"otrzymano dostep do pliku"<<std::endl;
}
else
std::cout<<"nie otrzymano dostep do pliku"<<std::endl;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Openfile1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;
char *file_name = OpenDialog1->FileName.c_str();


if(OpenDialog1->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------




void __fastcall TForm1::poleClick(TObject *Sender)
{
t1->CaretControlBefore(pole, NULL);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Memo1Change(TObject *Sender)
{
//Memo1->Lines->Text=dobrze;
}
//---------------------------------------------------------------------------



  int sek=0;
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{

AnsiString badpoint,goodpoint,minut, sekund,godzin;


goodpoint=IntToStr(dobrze);
Label1->Caption="wynik:"+goodpoint;

    badpoint=IntToStr(zle);
    Label3->Caption="b³êdy:"+badpoint;
    //Label4->Caption=godzin+":"+minut+":"+sekund;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label3Click(TObject *Sender)
{
    //AnsiString  badpoint;
    //badpoint=IntToStr(zle);
    //Label3->Caption="b³êdy:"+badpoint;
}
//---------------------------------------------------------------------------



void __fastcall TForm1::poleChange(TObject *Sender)
{
 t1->CaretControlAfter(this->pole);
 if (t1->isFinished(this->pole->CaretPos.x,this->pole->CaretPos.y) == true){
 char *w={" Koniec Tekstu!"};
  Timer1->Enabled = false;
  Timer2->Enabled = false;
  Timer3->Enabled = false;
 Application->MessageBoxA(w, " Koniec Programu", MB_OK);

 };
 }
//---------------------------------------------------------------------------

void __fastcall TForm1::Grnyrzd1Click(TObject *Sender)
{


if (gorny_rzad->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;

char *file_name = gorny_rzad->FileName.c_str();

if(gorny_rzad->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
Timer3->Enabled = true;
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Srodkowyrzd1Click(TObject *Sender)
{
if (srodkowy_rzad->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;
char *file_name = srodkowy_rzad->FileName.c_str();

if(srodkowy_rzad->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
Timer3->Enabled = true;
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Dolnyrzed1Click(TObject *Sender)
{
if (dolny_rzad->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;
char *file_name = dolny_rzad->FileName.c_str();

if(dolny_rzad->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);
;
FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
Timer3->Enabled = true;
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::d1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{
String FileContent;
std::string FileLine;
String SFileLine;
char *file_name = OpenDialog1->FileName.c_str();

if(OpenDialog1->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::cvmn1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;
char *file_name = OpenDialog1->FileName.c_str();
if(OpenDialog1->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::qwop1Click(TObject *Sender)
{
if (OpenDialog1->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;
char *file_name = OpenDialog1->FileName.c_str();

if(OpenDialog1->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);
FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Wszystkietrzyrzdy1Click(TObject *Sender)
{
if (wszystkie_trzy_rzedy->Execute())
{
String FileContent;
std::string FileLine;
String SFileLine;

char *file_name = wszystkie_trzy_rzedy->FileName.c_str();


if(wszystkie_trzy_rzedy->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
Timer3->Enabled = true;
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Cyfry1Click(TObject *Sender)
{
if (cyfry->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;

char *file_name = cyfry->FileName.c_str();


if(cyfry->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
Timer3->Enabled = true;
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Programistyczne1Click(TObject *Sender)
{
if (programistyczne->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;

char *file_name = programistyczne->FileName.c_str();

if(programistyczne->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
Timer3->Enabled = true;
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::te1Click(TObject *Sender)
{
if (przykladowe_teksty->Execute())
{

String FileContent;
std::string FileLine;
String SFileLine;

char *file_name = przykladowe_teksty->FileName.c_str();
if(przykladowe_teksty->FileName != NULL){
std::fstream plik;

plik.open(file_name,std::ios::in);
do{
std::getline(plik,FileLine);

FileContent+= FileLine.c_str(); //SFileLine;
}while (!plik.eof());

plik.close();

t1->SetTempCont(FileContent);
Timer3->Enabled = true;
pole->Text=t1->getAllLines();
t1->CaretControlBefore(this->pole, NULL);
};
}
}
//---------------------------------------------------------------------------
float skutecznosc=0;
void __fastcall TForm1::Timer3Timer(TObject *Sender)
{
AnsiString badpoint,goodpoint,minut, sekund,godzin, skut;
sek++;
float dobrzefloat=(float)dobrze;
float sekfloat=(float)sek;
skutecznosc=(dobrzefloat/sekfloat)*60;
int skutecznoscint;
skutecznoscint=(int)skutecznosc;
skut=(String)skutecznoscint;
int sec=0;
int minute=0;
int hour=0;
hour=sek/3600;
godzin=IntToStr(hour);
if(hour<10) godzin="0"+godzin;
minute=(sek-hour*3600)/60;
if(minute<10) minut="0"+minut;
minut=IntToStr(minute);
if(minute<10) minut="0"+minut;
sec=sek-hour*3600-minute*60;
sekund=IntToStr(sec);
if(sec<10) sekund="0"+sekund;
Label4->Caption=godzin+":"+minut+":"+sekund;
Label5->Caption="skutecznosc: "+skut+" zn/min";
}
//---------------------------------------------------------------------------



