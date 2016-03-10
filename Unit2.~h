//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Sockets.hpp>
#include <NMUDP.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
#include <IdUDPServer.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>


#include <vcl.h>
#include <windows.h>
#include <mmsystem.h>
#include <mmreg.h>


#include <vfw.h>           // VfW.H - Video for windows include file for WIN32
#include <Clipbrd.hpp>
#include <ScktComp.hpp>
#include <jpeg.hpp>

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
public:
    friend class TForm1;

    __published:    // IDE-managed Components
    TButton  *Button1;
    TDBImage *DBImage2;
    TDBImage *DBImage3;
    TDBImage *DBImage4;
    TDBImage *DBImage5;
    TDBImage *DBImage6;
    TDBImage *DBImage7;
    TDBImage *DBImage8;
    TDBImage *DBImage9;
    TDBImage *DBImage10;
    TDBImage *DBImage11;
    TDBImage *DBImage1;
    TIdUDPClient *IdUDPClient1;
    TIdUDPServer *IdUDPServer1;
    TBitBtn *BitBtn1;
    TImage *Image2;
    TImage *Image3;
    TImage *Image4;
    TImage *Image10;
    TImage *Image9;
    TImage *Image8;
    TImage *Image7;
    TImage *Image6;
    TImage *Image5;
    TImage *Image11;
    TTimer *Timer2;
    TImage *Image1;
    TPanel *Panel1;
    TPanel *Panel2;
    TPanel *Panel3;
    TPanel *Panel4;
    TPanel *Panel10;
    TPanel *Panel9;
    TPanel *Panel8;
    TPanel *Panel7;
    TPanel *Panel6;
    TPanel *Panel5;
    TLabel *Label1;
    TPanel *Panel11;
    TLabel *Label2;
    TLabel *Label3;
    TPanel *Panel12;
    TLabel *Label5;
    TEdit *Edit1;
    TButton *Button2;
    TLabel *Label6;
    TTimer *Timer1;
    TLabel *Label4;
    TImage *Image100;
    TImage *Image101;
    TImage *Image102;
    TImage *Image103;
    TImage *Image104;
    TImage *Image105;
    TImage *Image106;
    TImage *Image107;
    TImage *Image108;
    TImage *Image109;
    TImage *Image110;
    TTimer *Timer3;
    TButton *Button3;
    TButton *Button4;

    void __fastcall Button1Click(TObject *Sender);

    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

    void __fastcall BitBtn1Click(TObject *Sender);

    void __fastcall IdUDPServer1UDPRead(TObject *Sender,
                                        TStream *AData, TIdSocketHandle *ABinding);

    void __fastcall Timer2Timer(TObject *Sender);

    void __fastcall FormCreate(TObject *Sender);

    void __fastcall Edit1KeyPress(TObject *Sender, char &Key);

    void __fastcall Button2Click(TObject *Sender);

    void __fastcall Timer1Timer(TObject *Sender);

    void __fastcall Edit1Change(TObject *Sender);

    void __fastcall Button3Click(TObject *Sender);

    void __fastcall Button4Click(TObject *Sender);

private:    // User declarations



    TJPEGImage *jpg;
    TMemoryStream *strm;
    TJPEGImage *jpg2;
    byte *p;

    TDBImage *playerImage[20];
    TImage *playerRoleImage[20];
    TPanel *playerRolePanel[20];
    TImage *playerSpeakingLightening[20];

    HWND hWndC;
    int time;
    int b;
    int a;
    int cam;
    Graphics::TBitmap *Buffer;

    void start_cam();


public:        // User declarations

//void start_microphone(char* buf);
//void stop_microphone();
//char *buf1;
//char *buf2;
//char *buf3;
//char *buf4;
//long buf3_size;
//int zzz;
    friend void Button1Click(TObject *Sender);

    friend void start_cam();

    friend void startgame();

    friend void __fastcall ClientSocket1Read(TObject *Sender,
                                             TCustomWinSocket *Socket);

//friend void __fastcall TForm1::Button1Click(TObject *Sender);
    __fastcall TForm2(TComponent *Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
