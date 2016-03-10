//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ScktComp.hpp>
#include <Sockets.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Graphics.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------

enum Command
{
    PLAYER_ID, ROOM_INFO, START_GAME, AUTHORISATION, NEW_ROOM,
    ENTER_ROOM, LEAVE_ROOM, ROOMS_LIST, NEXT, GAME_INFO, END_GAME,
    SELECT, START_SPEAKING, STOP_SPEAKING, CHAT_SEND, CHAT_MESSAGE,FAILED,REGISTRATION,GET_SETTINGS,
    OUT_SETTINGS,SAVE_SETTINGS
};


class TForm1 : public TForm
{
public:
    friend class TForm2;

    __published:    // IDE-managed Components
    TImage *Image1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TEdit *Edit1;
    TEdit *Edit2;
    TImage *Image2;
    TClientSocket *ClientSocket1;
    TButton *Button2;
    TImage *Image4;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TImage *Image5;
    TImage *Image6;
    TImage *Image7;
    TImage *Image8;
    TImage *Image9;
    TImage *Image10;
    TImage *Image11;
    TImage *Image3;
    TImage *Image51;
    TImage *Image52;
    TImage *Image53;
    TImage *Image54;
    TImage *Image55;
    TImage *Image56;
    TImage *Image57;
    TImage *Image58;
    TLabel *Label111;
    TLabel *Label112;
    TLabel *Label113;
    TLabel *Label121;
    TLabel *Label122;
    TLabel *Label131;
    TLabel *Label132;
    TLabel *Label141;
    TLabel *Label142;
    TLabel *Label151;
    TLabel *Label152;
    TLabel *Label161;
    TLabel *Label162;
    TLabel *Label171;
    TLabel *Label172;
    TLabel *Label181;
    TLabel *Label182;
    TLabel *Label191;
    TLabel *Label192;
    TLabel *Label123;
    TLabel *Label133;
    TLabel *Label143;
    TLabel *Label153;
    TLabel *Label163;
    TLabel *Label173;
    TLabel *Label183;
    TLabel *Label193;
    TEdit *Edit3;
    TLabel *Label7;
    TLabel *Label8;
    TEdit *Edit4;
    TImage *Image12;
    TImage *Image61;
    TImage *Image62;
    TImage *Image63;
    TImage *Image64;
    TImage *Image65;
    TImage *Image66;
    TImage *Image67;
    TImage *Image68;
    TImage *Image69;
    TImage *Image71;
    TImage *Image72;
    TImage *Image73;
    TImage *Image74;
    TImage *Image75;
    TImage *Image76;
    TImage *Image77;
    TImage *Image78;
    TImage *Image79;
        TImage *Image13;
        TImage *Image14;
        TImage *Image15;

    void __fastcall Image2Click(TObject *Sender);

    void __fastcall FormCreate(TObject *Sender);

    void __fastcall ClientSocket1Error(TObject *Sender,
                                       TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
                                       int &ErrorCode);

    void __fastcall ClientSocket1Connect(TObject *Sender,
                                         TCustomWinSocket *Socket);

    void __fastcall ClientSocket1Read(TObject *Sender,
                                      TCustomWinSocket *Socket);

    void __fastcall TcpClient1Connect(TObject *Sender);

    void __fastcall Button1Click(TObject *Sender);

    void __fastcall Button2Click(TObject *Sender);

    void __fastcall Image12MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image12MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image12Click(TObject *Sender);

    void __fastcall Image71MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image71MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image72MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image72MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image73MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image73MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image74MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image74MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image75MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image75MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image76MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image76MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image77MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image77MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image78MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image78MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image79MouseDown(TObject *Sender,
                                     TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image79MouseUp(TObject *Sender,
                                   TMouseButton Button, TShiftState Shift, int X, int Y);

    void __fastcall Image71Click(TObject *Sender);

    void __fastcall Image72Click(TObject *Sender);

    void __fastcall Image73Click(TObject *Sender);

    void __fastcall Image74Click(TObject *Sender);

    void __fastcall Image75Click(TObject *Sender);

    void __fastcall Image76Click(TObject *Sender);

    void __fastcall Image77Click(TObject *Sender);

    void __fastcall Image78Click(TObject *Sender);

    void __fastcall Image79Click(TObject *Sender);
        void __fastcall Image13Click(TObject *Sender);
        void __fastcall Image14Click(TObject *Sender);
        void __fastcall Image2MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image2MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall Image13MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image13MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image14MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image14MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image15MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image15MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Image15Click(TObject *Sender);

private:    // User declarations

    int id;
    int room_id;
    int mas_room_id[20][20];
    int my_pos;
    int role;
    int enter;
    


public:        // User declarations

    friend class TForm4;
    friend class TForm5;

    friend void __fastcall Button1Click(TObject *Sender);

    friend void startgame();

    friend void oncl(int a);

    friend void chat();

    friend void onlogin();

    __fastcall TForm1(TComponent *Owner);
};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
