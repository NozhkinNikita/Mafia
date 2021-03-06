//--------------------------------------------------------------------------

#include <vcl.h>
#include <stdint.h>
#include <string>
#include <Formatter.h>

#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit4.h"
#include "Unit5.h"
#include <jpeg.hpp>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
TImage *arrayImage[30];
TLabel *textView[175];
String masr[20];


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner)
        : TForm(Owner)
{


}

//---------------------------------------------------------------------------
void __fastcall TForm1::Image2Click(TObject *Sender)
{
    int com = AUTHORISATION;
    String s2 = id;
   if (Edit1->Text==""||Edit2->Text=="")
    {
    ShowMessage("Empty field");
    return;
    }


    String login=Edit1->Text;
    for(int i=1;i<=login.Length();i++)
    {
    if (login[i]==' ')login[i]='_';
    }
    String pass=Edit2->Text;
    for(int i=1;i<=pass.Length();i++)
    {
    if (pass[i]==' ')pass[i]='_';
    }







    s2 = s2 + ' ' + com + ' ' + login + ' ' + pass;
    s2 = " " + s2;
    int nom = s2.Length();
    if (nom == 9)
      { nom = 11; } else
      {
      if (nom < 9)
      { nom++; } else
      { nom = nom + 2; }
      }
      String s1 = nom;
      s2 = s1 + s2;

      ClientSocket1->Socket->SendText(s2);

}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    this->enter=0;

    arrayImage[1] = Image51;
    arrayImage[2] = Image52;
    arrayImage[3] = Image53;
    arrayImage[4] = Image54;
    arrayImage[5] = Image55;
    arrayImage[6] = Image56;
    arrayImage[7] = Image57;
    arrayImage[8] = Image58;

    arrayImage[11] = Image61;
    arrayImage[12] = Image62;
    arrayImage[13] = Image63;
    arrayImage[14] = Image64;
    arrayImage[15] = Image65;
    arrayImage[16] = Image66;
    arrayImage[17] = Image67;
    arrayImage[18] = Image68;
    arrayImage[19] = Image69;


    arrayImage[21] = Image71;
    arrayImage[22] = Image72;
    arrayImage[23] = Image73;
    arrayImage[24] = Image74;
    arrayImage[25] = Image75;
    arrayImage[26] = Image76;
    arrayImage[27] = Image77;
    arrayImage[28] = Image78;
    arrayImage[29] = Image79;


    textView[11] = Label111;
    textView[12] = Label112;
    textView[13] = Label113;

    textView[21] = Label121;
    textView[22] = Label122;
    textView[23] = Label123;

    textView[31] = Label131;
    textView[32] = Label132;
    textView[33] = Label133;

    textView[41] = Label141;
    textView[42] = Label142;
    textView[43] = Label143;

    textView[51] = Label151;
    textView[52] = Label152;
    textView[53] = Label153;


    textView[61] = Label161;
    textView[62] = Label162;
    textView[63] = Label163;


    textView[71] = Label171;
    textView[72] = Label172;
    textView[73] = Label173;

    textView[81] = Label181;
    textView[82] = Label182;
    textView[83] = Label183;

    textView[91] = Label191;
    textView[92] = Label192;
    textView[93] = Label193;



    ClientSocket1->Host = "192.168.43.116";
    ClientSocket1->Address = "192.168.43.116";
    ClientSocket1->Port = 7777;


    try
    {
        if (!ClientSocket1->Active)
        {
            ClientSocket1->Active = true;
        }
    }
    catch (Exception &e)
    {
        ShowMessage("");
    }
    }

//---------------------------------------------------------------------------
void clear(int a)
{
    for (int i = 1; i <= 9; i++)
    {
        textView[i * 10 + 1]->Visible = false;
        textView[i * 10 + 2]->Visible = false;
        textView[i * 10 + 3]->Visible = false;
        if (i < 9)
        {
            arrayImage[i]->Visible = false;

        }
        arrayImage[i + 10]->Visible = false;
        arrayImage[i + 20]->Visible = false;
    };
}

void __fastcall TForm1::ClientSocket1Error(TObject *Sender,
                                           TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{

//Image3->Visible=false;
    if (ErrorCode == 10061)
    {
        ShowMessage("Connection error");

        ErrorCode = 0;
    }

    if (ErrorCode == 11004)
    {
        ShowMessage("server not found");

        ErrorCode = 0;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClientSocket1Connect(TObject *Sender,
                                             TCustomWinSocket *Socket)
{

    ShowMessage("connection ok");
//Image3->Visible=false;

}

//---------------------------------------------------------------------------
void startgame()
{

    switch (Form1->role)
    {

        case (1):
            Form2->playerRolePanel[Form1->my_pos]->Visible = true;
            Form2->playerRoleImage[Form1->my_pos]->Picture->LoadFromFile("img/���.jpg");

            break;

        case 2:
            Form2->playerRolePanel[Form1->my_pos]->Visible = true;
            Form2->playerRoleImage[Form1->my_pos]->Picture->LoadFromFile("img/doc.jpg");

            break;
        case 3:
            Form2->playerRolePanel[Form1->my_pos]->Visible = true;
            Form2->playerRoleImage[Form1->my_pos]->Picture->LoadFromFile("img/maf.jpg");

            break;
        case 4:
            Form2->playerRolePanel[Form1->my_pos]->Visible = true;
            Form2->playerRoleImage[Form1->my_pos]->Picture->LoadFromFile("img/mir.jpg");

            break;
        case 0:
            Form2->playerRolePanel[Form1->my_pos]->Visible = true;
            Form2->playerRoleImage[Form1->my_pos]->Picture->LoadFromFile("img/ved.jpg");
            Form2->Panel12->Visible = true;

            Form2->BitBtn1->Visible = true;
            Form2->Timer1->Enabled = true;
            break;
    }
    Form2->Button1->Enabled = false;
    Form2->Label3->Visible = true;
    Form2->Label4->Visible = true;

}

void newlabel(TLabel *l, String s, int x, int y, int n)
{
    l->Parent = Form1;
    l->Left = x;
    l->Top = y;
    l->Name = "Edit" + IntToStr(n);
    l->Caption = s;
    l->Font->Color = clWhite;
    l->Font->Size = 20;
    l->Font->Name = "MS UI Gothic";
    l->Color = clGray;
}

void newimage(TImage *i, int x, int y, int n)
{
    i->Top = y;
    i->Left = x;
    i->Picture->LoadFromFile("img/lin.bmp");
    i->Parent = Form1;
    i->Name = "Image" + IntToStr(n);
    i->Height = 4;
    i->Width = 500;
}

void draw_list(int number, int status, int safe, int n_current, int n_max, int id_room)
{
    if (number < 9)
    {
        arrayImage[number]->Visible = true;
    };
    textView[number * 10 + 1]->Caption = number;
    if (status == 0)
    {
        textView[number * 10 + 2]->Caption = "waiting";
    }
    else
    {
        textView[number * 10 + 2]->Caption = "playing";
    }
    textView[number * 10 + 3]->Caption = (String) n_current + "/" + (String) n_max;
    textView[number * 10 + 1]->Visible = true;
    textView[number * 10 + 2]->Visible = true;
    textView[number * 10 + 3]->Visible = true;
    arrayImage[20 + number]->Visible = true;
    if (safe == 1)
    {
        arrayImage[10 + number]->Visible = true;
    }
};

void onlogin()
{
    Form1->Label2->Visible = false;
    Form1->Label3->Visible = false;
    Form1->Image1->Visible = false;
    Form1->Image13->Visible = false;
    Form1->Image14->Visible = false;
    Form1->Image4->Visible = true;
    Form1->Image4->Left = 0;
    Form1->Image4->Top = 0;

    Form1->Edit1->Visible = false;
    Form1->Edit2->Visible = false;

    Form1->Label4->Visible = true;
    Form1->Label5->Visible = true;
    Form1->Label6->Visible = true;


    Form1->Label7->Visible = true;
    Form1->Label8->Visible = true;

    Form1->Edit3->Visible = true;
    Form1->Edit4->Visible = true;


    Form1->Image3->Visible = true;
    Form1->Image5->Visible = true;
    Form1->Image6->Visible = true;
    Form1->Image7->Visible = true;
    Form1->Image8->Visible = true;
    Form1->Image9->Visible = true;
    Form1->Image10->Visible = true;
    Form1->Image11->Visible = true;
    Form1->Image12->Visible = true;


    if(Form1->enter==0)
    {
    Form1->Image15->Visible=true;
    }
    Form1->Image12->Visible = true;
    //Form1->Label4->Top=60;
    //Form1->Label5->Top=60;
    //Form1->Label6->Top=60;

    //Form1->Label4->Left=80;
    //Form1->Label5->Left=350;
    //Form1->Label6->Left=635;
};

void __fastcall TForm1::ClientSocket1Read(TObject *Sender,
                                          TCustomWinSocket *Socket)
{


    String message = Socket->ReceiveText();
//ShowMessage(s);
//s="30 7 5 1 1 3 8 53 1 0 2 7 13 0 1 0 10 54 0 0 3 15 55 1 1 9 9 59";
//s=s+' ';
    String string  = message;
    int count = 0;
    while (string != "")
    {
        int number = string.Pos(' ');
        String str = string.SubString(1, number - 1);
        int length = str.ToInt();
        count++;
        masr[count] = string.SubString(1, length);
        string.Delete(1, length);

    }
    for (int qur = 1; qur <= count; qur++)
    {
        message = masr[qur];
        message = message + " ";
        int number= message.Pos(' ');

        String str = message.SubString(1, number - 1);
        int length = str.ToInt();
        message.Delete(1, number);


        number = message.Pos(' ');
        str = message.SubString(1, number - 1);
        int command = str.ToInt();
        message.Delete(1, number);
        switch (command)
        {


            case (PLAYER_ID):
            {
                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                id = str.ToInt();
                message.Delete(1, number);


            }
                break;

            case (ROOMS_LIST):
            {
                onlogin();
                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                int n = str.ToInt();
                message.Delete(1, number);

                clear(n);
                for (int i = 1; i <= n; i++)
                {
                    number = message.Pos(' ');
                    str = message.SubString(1, number - 1);
                    int status = str.ToInt();
                    message.Delete(1, number);

                    number = message.Pos(' ');
                    str = message.SubString(1, number - 1);
                    int safe = str.ToInt();
                    message.Delete(1, number);

                    number = message.Pos(' ');
                    str = message.SubString(1, number - 1);
                    int n_current = str.ToInt();
                    message.Delete(1, number);

                    number = message.Pos(' ');
                    str = message.SubString(1, number - 1);
                    int n_max = str.ToInt();
                    message.Delete(1, number);

                    number = message.Pos(' ');
                    str = message.SubString(1, number - 1);
                    int id_room = str.ToInt();
                    message.Delete(1, number);

                    Form1->mas_room_id[i][1] = id_room;
                    Form1->mas_room_id[i][2] = safe;
                    draw_list(i, status, safe, n_current, n_max, id_room);
                }
            }
                break;

            case (ROOM_INFO):
            {


                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                message.Delete(1, number);
                if (str != "1")
                {
                    return;
                };
                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                int n = str.ToInt();
                message.Delete(1, number);

                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                Form1->my_pos = str.ToInt();
                message.Delete(1, number);

                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                Form1->room_id = str.ToInt();
                message.Delete(1, number);

                number = message.Pos(' ');
                str = message.SubString(1, message - 1);


                for (int i = 1; i <= 11; i++)
                {
                    Form2->playerImage[i - 1]->Visible = false;

                }
                for (int i = 1; i <= 11; i++)
                {

                    if (str[i] == '1')
                    {
                        Form2->playerImage[i - 1]->Visible = true;
                    }
                }
                Form4->Memo1->Clear();

                Form2->Visible = true;
                Form4->Visible = true;
                Form1->Visible = false;
                Form2->start_cam();


                message.Delete(1, number);

            }
                break;

            case (START_GAME):
            {

                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                Form1->role = str.ToInt();
                message.Delete(1, number);
                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                Form1->my_pos = str.ToInt();

                startgame();

                break;
            }
            case (GAME_INFO):
            {
                Form2->time = 60;

                String str1, str2, str3;

                number = message.Pos(' ');
                str1 = message.SubString(1, number - 1);
                message.Delete(1, number);

                number = message.Pos(' ');
                str2 = message.SubString(1, number - 1);
                message.Delete(1, number);

                number = message.Pos(' ');
                str3 = message.SubString(1, number - 1);
                message.Delete(1, number);

                for (int i = 1; i < str1.Length(); i++)
                {
                    if (str1[i] == '_')
                    { str1[i] = ' '; }

                };
                for (int i = 1; i < str2.Length(); i++)
                {
                    if (str2[i] == '_')
                    { str2[i] = ' '; }

                }
                for (int i = 1; i < str3.Length(); i++)
                {
                    if (str3[i] == '_')
                    { str3[i] = ' '; }

                }
                Form2->Label3->Caption = str1;
                Form2->Label4->Caption = str2;
                Form2->BitBtn1->Caption = str3;

                if (str1 == 'Day')
                {
                    Form2->Label5->Caption = "Number of player";
                    Form2->Button2->Caption = "exhibit";
                }
                else if (str1 == "Night")
                {
                    Form2->Label5->Caption = "Number of player";
                    if (str2 == "Mafias wake up")
                    {
                        Form2->Button2->Caption = "Kill";
                    } else
                    {
                        Form2->Button2->Caption = "Heal";
                    }
                }
                else if (str1 == "Voting")
                {
                    Form2->Label5->Caption = "Count";
                    Form2->Button2->Caption = "Vote";
                }
            }
                break;
            case (END_GAME):
            {
                Form2->Button1->Enabled = true;
                Form2->Timer1->Enabled = false;
                Form2->Panel12->Visible = false;
                Form2->BitBtn1->Visible = false;
            }
                break;
            case (START_SPEAKING):
            {
                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                int n_current = str.ToInt();
                message.Delete(1, number);
                Form2->playerSpeakingLightening[n_current]->Visible = true;
                //if(Form1->my_pos==n_current)
                {
                    //Form2->start_microphone(Form2->buf1);
                    //Form2->Timer3->Enabled=true;
                }
            }
                break;
            case (STOP_SPEAKING):
            {
                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                int n_current = str.ToInt();
                message.Delete(1, number);
                Form2->playerSpeakingLightening[n_current]->Visible = false;
                //if(Form1->my_pos==n_current)
                //Form2->stop_microphone();
                //Form2->Timer3->Enabled=false;
            }
                break;

            case (CHAT_MESSAGE):
            {
                number = message.Pos(' ');
                str = message.SubString(1, number - 1);
                int n_pos = str.ToInt();
                message.Delete(1, number);

                number = message.Pos(' ');
                WideString s2 = message.SubString(1, number - 1);
                for (int i = 1; i <= s2.Length(); i++)
                {
                    if (s2[i] == '_')
                    { s2[i] = ' '; }
                }
                Form4->Memo1->Lines->Add("[" + (String) n_pos + "] " + s2);


            }
                break;
            case (FAILED):
            {
            number = message.Pos(' ');
            str = message.SubString(1, number - 1);
            int error = str.ToInt();
            switch(error)
                {
                case(0):
                ShowMessage("Login busy");
                break;
                case (1):
                ShowMessage("Wrong password");
                break;
                }
            }
                break;


            case (OUT_SETTINGS):
            {
            number = message.Pos(' ');
            String name = message.SubString(1, number - 1);
            message.Delete(1, number);

            number = message.Pos(' ');
            String age = message.SubString(1, number - 1);
            message.Delete(1, number);

            number = message.Pos(' ');
            String email = message.SubString(1, number - 1);
            message.Delete(1, number);

            number = message.Pos(' ');
            String fb = message.SubString(1, number - 1);
            message.Delete(1, number);

            number = message.Pos(' ');
            String vk = message.SubString(1, number - 1);
            message.Delete(1, number);

             number = message.Pos(' ');
            String additional = message.SubString(1, number - 1);
            message.Delete(1, number);


            Form5->Edit1->Text=name;
            Form5->Edit2->Text=age;
            Form5->Edit3->Text=email;
            Form5->Edit4->Text=fb;
            Form5->Edit5->Text=vk;
            Form5->Edit6->Text=additional;



            }
                break;



        };
    };
}
//---------------------------------------------------------------------------


void __fastcall TForm1::TcpClient1Connect(TObject *Sender)
{  /*
 TcpClient1->Connect();
 */
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ClientSocket1->Socket->SendText(Edit1->Text);
    Form2->Visible = true;
    Form1->Visible = false;
    Form1->my_pos = 1;
    Form2->playerImage[1]->Visible = true;
    Form2->start_cam();
// AnsiString InputString = InputBox("Password", "Password", "");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
    exit(0);
}


//---------------------------------------------------------------------------

void __fastcall TForm1::Image12MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image12->Picture->LoadFromFile("img/ng1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image12->Picture->LoadFromFile("img/cr.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image12Click(TObject *Sender)
{

    String s;

    String str = Edit3->Text;
    String s2 = Edit4->Text;
    int pl;
    try
    {
        pl = str.ToInt();

    }
    catch (EConvertError &e)
    {
        pl = 0;
        Edit3->Text = "";
        ShowMessage("Wrong players");
        return;
        //return errorCode89;
    }
    if ((pl < 9) || (pl > 11))
    {
        ShowMessage("Wrong players");
        return;
    }


    if (s2.Pos(' ') != 0)
    {


        ShowMessage("Wrong password(only latinic and number)");
        return;
    }
    if (s2 == "")
    {
        s2 = "nopass";
    }
    String s3, s4;
    s3 = id;
    s3 = s3 + ' ';
    s3 = s3 + NEW_ROOM;
    s3 = s3 + ' ';
    s3 = s3 + pl;
    s3 = s3 + ' ';
    s3 = s3 + s2;


    //ShowMessage(s3);
    s3 = " " + s3;
    int a = s3.Length();
    if (a == 9)
    { a = 11; } else
    {
        if (a < 9)
        { a++; } else
        { a = a + 2; }
    }

    str = a;
    s3 = str + s3;

    ClientSocket1->Socket->SendText(s3);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image71MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image71->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image71MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image71->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image72MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image72->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image72MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image72->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image73MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image73->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image73MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image73->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image74MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image74->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image74MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image74->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image75MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image75->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image75MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image75->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image76MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image76->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image76MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image76->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image77MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image77->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image77MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image77->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image78MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image78->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image78MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image78->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image79MouseDown(TObject *Sender,
                                         TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image79->Picture->LoadFromFile("img/ent2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image79MouseUp(TObject *Sender,
                                       TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Image79->Picture->LoadFromFile("img/ent1.jpg");
}
//---------------------------------------------------------------------------


void oncl(int numberOfRoom)
{
//ShowMessage(Form1->mas_room_id[a][1]);
    String s, str, s2, s3;
   // ShowMessage(Form1->mas_room_id[a][1]);
    AnsiString pass;
    if (Form1->mas_room_id[numberOfRoom][2] == 1)
    { pass = InputBox("Password", "Password", ""); }
    if (pass == "")
    {
        pass = "nopass";
    }
    s = (String) Form1->id + ' ' + (String) ENTER_ROOM + ' ' + (String) Form1->mas_room_id[numberOfRoom][1] + ' ' + pass;
    //ShowMessage(s);

    s = " " + s;
    int number = s.Length();
    if (number == 9)
    { number = 11; } else
    {
        if (number < 9)
        { number++; } else
        { number = number + 2; }
    }

    str = number;
    s = str + s;

    Form1->ClientSocket1->Socket->SendText(s);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image71Click(TObject *Sender)
{
    oncl(1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image72Click(TObject *Sender)
{
    oncl(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image73Click(TObject *Sender)
{
    oncl(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image74Click(TObject *Sender)
{
    oncl(4);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image75Click(TObject *Sender)
{
    oncl(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image76Click(TObject *Sender)
{
    oncl(6);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image77Click(TObject *Sender)
{
    oncl(7);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image78Click(TObject *Sender)
{
    oncl(8);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image79Click(TObject *Sender)
{
    oncl(9);
}
//---------------------------------------------------------------------------











void __fastcall TForm1::Image13Click(TObject *Sender)
{
     int com = REGISTRATION;
    String s2 = id;
    if (Edit1->Text==""||Edit2->Text=="")
    {
    ShowMessage("Empty field");
    return;
    }
    String login=Edit1->Text;
    for(int i=1;i<=login.Length();i++)
    {
    if (login[i]==' ')login[i]='_';
    }
    String pass=Edit2->Text;
    for(int i=1;i<=pass.Length();i++)
    {
    if (pass[i]==' ')pass[i]='_';
    }


    s2 = s2 + ' ' + com + ' ' + login + ' ' + pass;
    s2 = " " + s2;
    int number = s2.Length();
    if (number == 9)
      { number = 11; } else
      {
      if (number < 9)
      { number++; } else
      { number = number + 2; }
      }
      String str = number;
      s2 = str + s2;

      ClientSocket1->Socket->SendText(s2);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image14Click(TObject *Sender)
{

    this->enter=1;
    int com = AUTHORISATION;
    String s2 = id;
    s2 = s2 + ' ' + com + ' ' + "guest" + ' ' + "guest";
    s2 = " " + s2;
    int number = s2.Length();
    if (number == 9)
      { number = 11; } else
      {
      if (number < 9)
      { number++; } else
      { number = number + 2; }
      }
      String str = number;
      s2 = str + s2;

      ClientSocket1->Socket->SendText(s2);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Image2->Picture->LoadFromFile("img/enter2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
Image2->Picture->LoadFromFile("img/enter.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image13MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Image13->Picture->LoadFromFile("img/signup2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image13MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Image13->Picture->LoadFromFile("img/signup.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image14MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Image14->Picture->LoadFromFile("img/goust2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image14MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Image14->Picture->LoadFromFile("img/goust.jpg");
}
//---------------------------------------------------------------------------






void __fastcall TForm1::Image15MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Image15->Picture->LoadFromFile("img/settings2.jpg");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image15MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
Image15->Picture->LoadFromFile("img/settings.jpg");        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image15Click(TObject *Sender)
{
Form5->Visible=false;
Form5->Visible=true;
    

String s;


    String s3, s4;
    s3 = id;
    s3 = s3 + ' ';
    s3 = s3 + GET_SETTINGS;
    

    //ShowMessage(s3);
    s3 = " " + s3;
    int a = s3.Length();
    if (a == 9)
    { a = 11; } else
    {
        if (a < 9)
        { a++; } else
        { a = a + 2; }
    }

    String str = a;
    s3 = str + s3;

    ClientSocket1->Socket->SendText(s3);












}
//---------------------------------------------------------------------------



