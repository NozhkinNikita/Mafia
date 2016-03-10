//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent *Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{


    String message;
    message = CHAT_SEND;
    message = (String) Form1->id + ' ' + message;
    //ShowMessage(message);

    WideString chatMessage;
    chatMessage = Edit1->Text;


    for (int i = 1; i <= chatMessage.Length(); i++)
    {
        if (chatMessage[i] == ' ')
        {
            chatMessage[i] = '_';
        }
    }


    message = message + " " + chatMessage;


    message = " " + message;
    int messageLength = message.Length();
    if(messageLength == 98)
    {messageLength == 111; }else
    if (messageLength == 9)
    { messageLength = 11; } else
    {
        if (messageLength < 9)
        { messageLength++; } else
        if(messageLength>100)
        {messageLength = messageLength + 3;}else
        { messageLength = messageLength + 2; }
    }


    message = (String) messageLength + message;


    Form1->ClientSocket1->Socket->SendText(message);

}
//---------------------------------------------------------------------------


