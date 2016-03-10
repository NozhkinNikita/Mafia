//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include <fstream>
#include <stdio.h>
#include <iostream>


#include <windows.h>
#include <mmsystem.h>
#include <mmsystem>
#include <mmreg.h>


#include <vfw.h>           // VfW.H - Video for windows include file for WIN32
#include <Clipbrd.hpp>
#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
WAVEHDR wavbuf;
WAVEHDR wavbuf2;
bool recording;
bool recorded;
HWAVEIN hwi;
WAVEFORMATEX wavform;
HWAVEIN hwi2;
WAVEFORMATEX wavform2;

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent *Owner)
        : TForm(Owner)
{
    playerImage[1] = DBImage1;
    playerImage[2] = DBImage2;
    playerImage[3] = DBImage3;
    playerImage[4] = DBImage4;
    playerImage[5] = DBImage5;
    playerImage[6] = DBImage6;
    playerImage[7] = DBImage7;
    playerImage[8] = DBImage8;
    playerImage[9] = DBImage9;
    playerImage[10] = DBImage10;
    playerImage[0] = DBImage11;


    playerRoleImage[1] = Image1;
    playerRoleImage[2] = Image2;
    playerRoleImage[3] = Image3;
    playerRoleImage[4] = Image4;
    playerRoleImage[5] = Image5;
    playerRoleImage[6] = Image6;
    playerRoleImage[7] = Image7;
    playerRoleImage[8] = Image8;
    playerRoleImage[9] = Image9;
    playerRoleImage[10] = Image10;
    playerRoleImage[0] = Image11;

    playerRolePanel[1] = Panel1;
    playerRolePanel[2] = Panel2;
    playerRolePanel[3] = Panel3;
    playerRolePanel[4] = Panel4;
    playerRolePanel[5] = Panel5;
    playerRolePanel[6] = Panel6;
    playerRolePanel[7] = Panel7;
    playerRolePanel[8] = Panel8;
    playerRolePanel[9] = Panel9;
    playerRolePanel[10] = Panel10;
    playerRolePanel[0] = Panel11;


    playerSpeakingLightening[1] = Image100;
    playerSpeakingLightening[2] = Image101;
    playerSpeakingLightening[3] = Image102;
    playerSpeakingLightening[4] = Image103;
    playerSpeakingLightening[5] = Image109;
    playerSpeakingLightening[6] = Image108;
    playerSpeakingLightening[7] = Image107;
    playerSpeakingLightening[8] = Image106;
    playerSpeakingLightening[9] = Image105;
    playerSpeakingLightening[10] = Image104;
    playerSpeakingLightening[0] = Image110;
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{
    Form1->Visible = true;
    Form2->Visible = false;
    Form4->Visible = false;

    Form2->cam = 0;
    Form2->Timer2->Enabled = False;
    capDriverDisconnect(Form2->hWndC);
    DestroyWindow(Form2->hWndC);
    String message;
    message = Form1->id;
    message = message + ' ' + String(LEAVE_ROOM);


    message = " " + message;
    int messageLength = message.Length();
    if (messageLength == 9)
    { messageLength = 11; } else
    {
        if (messageLength < 9)
        { messageLength++; } else
        { messageLength = messageLength + 2; }
    }

    message = String(messageLength) + message;


    Form1->ClientSocket1->Socket->SendText(message);


    Form2->DBImage1->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage2->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage3->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage4->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage5->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage6->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage7->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage8->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage9->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage10->Picture->LoadFromFile("img/101.jpg");
    Form2->DBImage11->Picture->LoadFromFile("img/101.jpg");

    Panel1->Visible = false;
    Panel2->Visible = false;
    Panel3->Visible = false;
    Panel4->Visible = false;
    Panel5->Visible = false;
    Panel6->Visible = false;
    Panel7->Visible = false;
    Panel8->Visible = false;
    Panel9->Visible = false;
    Panel10->Visible = false;
    Panel11->Visible = false;


    Panel12->Visible = false;
    Label3->Visible = false;
    Label4->Visible = false;
    BitBtn1->Visible = false;
}
//---------------------------------------------------------------------------




void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    capDriverDisconnect(hWndC);          // ����������� �� ������ (��� ��������� ������)
    DestroyWindow(hWndC);
    exit(0);

}

//---------------------------------------------------------------------------
void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{


    String message;
    message = NEXT;
    message = (String) Form1->id + ' ' + message;
    //ShowMessage(message);

    message = " " + message;
    int messageLength = message.Length();
    if (messageLength == 9)
    { messageLength = 11; } else
    {
        if (messageLength < 9)
        { messageLength++; } else
        { messageLength = messageLength + 2; }
    }


    message = (String) messageLength + message;
    Form1->ClientSocket1->Socket->SendText(message);
}

//---------------------------------------------------------------------------
void __fastcall TForm2::IdUDPServer1UDPRead(TObject *Sender,
                                            TStream *AData, TIdSocketHandle *ABinding)
{
    byte ccc;
    AData->Read(&ccc, 1);
    Label1->Caption = IntToStr(Form2->a++);
    if (ccc == 113)
    {

        AData->Read(Form2->p, AData->Size - 1);
        int cur = 0;
        while (cur < AData->Size - 1)
        {
            TMemoryStream *strm = new TMemoryStream();
            byte b = Form2->p[cur];
            cur++;
            byte c = Form2->p[cur];
            cur++;
            int g = (b << 8) + c;
            byte a = Form2->p[cur];
            cur++;
            for (int i = 1; i <= g; i++)
            {
                strm->Write(&(Form2->p[cur]), 1);
                cur++;
            };

            try
            {
                strm->Seek(0, 0);
                if (strm->Size > 2000)
                {
                    Form2->jpg2->LoadFromStream(strm);

                    Form2->playerImage[a]->Picture->Assign(Form2->jpg2);
                }
            } catch (...)
            {

//ShowMessage(*a);
                Form2->jpg2->Free();
                Form2->playerImage[a]->Picture->Free();
                Label1->Caption = (String) AData->Size + " " + (String) a;
            };
            strm->Free();

//jpg->Free();
//strm->Free();
        }
    }
    else
    {

        char *p = new char[20000];
        AData->Read(p, AData->Size - 1);
        wavbuf2.lpData = p;

        waveOutOpen(&hwi2, WAVE_MAPPER, &wavform2, (DWORD) Form2->Handle, 0, CALLBACK_WINDOW);

        wavbuf2.dwBufferLength = AData->Size - 1;
        wavbuf2.dwBytesRecorded = wavbuf2.dwBufferLength;

        waveOutPrepareHeader(hwi2, &wavbuf2, sizeof(wavbuf2));
        waveOutWrite(hwi2, &wavbuf2, sizeof(wavbuf2));
        waveOutClose(hwi2);

    }
    int tt = 0;
//Sleep((unsigned int)(tt));

}

//---------------------------------------------------------------------------


void __fastcall TForm2::Timer2Timer(TObject *Sender)
{
    capGrabFrame(Form2->hWndC);
    if (capEditCopy(Form2->hWndC))
    {
        Form2->Buffer->LoadFromClipboardFormat(CF_BITMAP, Clipboard()->GetAsHandle(CF_BITMAP), 0);
        Form2->jpg->Assign(Form2->Buffer);
        Form2->jpg->CompressionQuality = 40;
//jpg->PixelFormat=jf24Bit;

        Form2->jpg->Compress();
//jpg->SaveToFile("222.jpg");
        Form2->jpg->SaveToStream(Form2->strm);
        Form2->strm->Position = Form2->strm->Size;
        byte ooo = 113;
        Form2->strm->Write(&ooo, 1);

        void *p;

        Form2->strm->Position = 0;
        p = Form2->strm->Memory;


        IdUDPServer1->SendBuffer("192.168.43.116", 7777, p, Form2->strm->Size);
        Label6->Caption = IntToStr(Form2->b++);
//strm->Free();

        Sleep((unsigned int) (0));

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
//DBImage11->DoubleBuffered=true;
    cam = 0;
    a = 0;
    b = 0;
    DBImage1->Picture->LoadFromFile("img/101.jpg");
    DBImage2->Picture->LoadFromFile("img/101.jpg");
    DBImage3->Picture->LoadFromFile("img/101.jpg");
    DBImage4->Picture->LoadFromFile("img/101.jpg");
    DBImage5->Picture->LoadFromFile("img/101.jpg");
    DBImage6->Picture->LoadFromFile("img/101.jpg");
    DBImage7->Picture->LoadFromFile("img/101.jpg");
    DBImage8->Picture->LoadFromFile("img/101.jpg");
    DBImage9->Picture->LoadFromFile("img/101.jpg");
    DBImage10->Picture->LoadFromFile("img/101.jpg");
    DBImage11->Picture->LoadFromFile("img/101.jpg");
    Image1->BringToFront();
    Image2->BringToFront();
    Image3->BringToFront();
    Image4->BringToFront();
    Image5->BringToFront();
    Image6->BringToFront();
    Image7->BringToFront();
    Image8->BringToFront();
    Image9->BringToFront();
    Image10->BringToFront();
    Image11->BringToFront();

    Form2->jpg = new TJPEGImage();
    Form2->strm = new TMemoryStream();
    Form2->jpg2 = new TJPEGImage();
    Form2->p = new byte[75000];
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Edit1KeyPress(TObject *Sender, char &Key)
{

    if (!(Key >= 0 && Key <= 9))
    {
        String s = Edit1->Text;
        s.Delete(s.Length(), 1);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
    if (Edit1->Text == "")
    { return; }
    String message;
    message = SELECT;
    message = (String) Form1->id + ' ' + message + ' ' + Edit1->Text;
    //ShowMessage(message);
    message = " " + message;
    int messageLength = message.Length();
    if (messageLength == 9)
    { messageLength = 11; } else
    {
        if (messageLength < 9)
        { messageLength++; } else
        { messageLength = messageLength + 2; }
    }

    message = (String) messageLength + message;
    Form1->ClientSocket1->Socket->SendText(message);
}

//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
    if (Form2->time == 0)
    {
        return;
    }
    Form2->time--;
    Label2->Caption = (String) Form2->time;
}

//---------------------------------------------------------------------------




void __fastcall TForm2::Edit1Change(TObject *Sender)
{/*
String s=Edit1->Text;
if(!(s[s.Length()]>='0' ||s[s.Length()]<='0'))
s.Delete(s.Length(),1);
Edit1->Text=s;
*/
    String s = Edit1->Text;
    try
    {
        StrToInt(s);
    }
    catch (...)
    {
        Edit1->Text = "";
    }
}

//---------------------------------------------------------------------------
/*
void chat()
{


    String message;
    message = CHAT_SEND;
    message = (String) Form1->id + ' ' + message;
    //ShowMessage(message);

    String s4;


    for (int i = 1; i <= s4.Length(); i++)
    {
        if (s4[i] == ' ')
        {
            s4[i] = '_';
        }
    }
    message = message + " " + s4;
    message = " " + message;
    int a = message.Length();
    if (a == 9)
    { a = 11; } else
    {
        if (a < 9)
        { a++; } else
        { a = a + 2; }
    }
    message = (String) a + message;
    Form1->ClientSocket1->Socket->SendText(message);
}
*/
void __fastcall TForm2::Button3Click(TObject *Sender)
{

    Form4->Visible = false;
    Form4->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
    Form4->Visible = false;
}

//---------------------------------------------------------------------------
void TForm2::start_cam()
{
    if (Form2->cam == 1)
    { return; }
    Form2->cam = 1;
    Form2->hWndC = capCreateCaptureWindow("", WS_CHILD, Form2->Left, Form2->Top, Form2->Width,
                                          Form2->Height, Form2->Handle, 11011);
    Form2->Buffer = new Graphics::TBitmap;
    capDriverConnect(Form2->hWndC, 0);           // ������������ � [������] ������ (��� ���������� ���������)
    capGrabFrame(Form2->hWndC);                 // ���������� � ���� ���� � ������
    bool capOK = capEditCopy(Form2->hWndC);       // �������� ���� � ����� ������
    capDriverDisconnect(Form2->hWndC);          // ����������� �� ������ (��� ��������� ������)
    DestroyWindow(Form2->hWndC);                // ������� ����
    if (capOK)
    {                         // ���� �� ����������
        TClipboard *pCB = Clipboard();                     // ����� ������ windows
        Graphics::TBitmap *Buffer = new Graphics::TBitmap; // ���� ������ ���� �����
        Buffer->LoadFromClipboardFormat(CF_BITMAP, pCB->GetAsHandle(CF_BITMAP), 0);// ��������� �� ������
//     Form1->Canvas->Draw(0,0,Buffer);                 // �� � ��������, ����������
        //    Buffer->SaveToFile("kadr.bmp");                  // ��� � ���� ����������
//     ...                                            // ��� ��� ����
        pCB->Clear();                                    // ������� ����� ������
        delete Buffer;                                   // ����������� ������
    }

    Form2->hWndC = capCreateCaptureWindow("", WS_CHILD, Form2->Left, Form2->Top, Form2->Width,
                                          Form2->Height, Form2->Handle, 11011);
    capDriverConnect(Form2->hWndC, 0);

    Form2->Timer2->Enabled = true;
}

