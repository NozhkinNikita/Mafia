//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <vfw.h>
#include "Unit1.h"
   #include <Clipbrd.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
HWND hWndC;
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
   capGrabFrame(hWndC);

       bool capOK=capEditCopy(hWndC);       // �������� ���� � ����� ������
  if (capOK) {


     TClipboard *pCB=Clipboard();                     // ����� ������ windows
     Graphics::TBitmap *Buffer=new Graphics::TBitmap; // ���� ������ ���� �����
     DBImage1->Picture->LoadFromClipboardFormat(CF_BITMAP,pCB->GetAsHandle(CF_BITMAP),0);



  }











}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
/*
Graphics::TBitmap *Buffer;
hWndC=capCreateCaptureWindow("",WS_CHILD, this->Left, this->Top, this->Width, this->Height, this->Handle, 11011);
Buffer=new Graphics::TBitmap;
  capDriverConnect(hWndC,0);           // ������������ � [������] ������ (��� ���������� ���������)
  capGrabFrame(hWndC);                 // ���������� � ���� ���� � ������
   bool capOK=capEditCopy(hWndC);       // �������� ���� � ����� ������
  capDriverDisconnect(hWndC);          // ����������� �� ������ (��� ��������� ������)
  DestroyWindow(hWndC);                // ������� ����
  if (capOK) {                        // ���� �� ����������
     TClipboard *pCB=Clipboard();                     // ����� ������ windows
     Graphics::TBitmap *Buffer=new Graphics::TBitmap; // ���� ������ ���� �����
     Buffer->LoadFromClipboardFormat(CF_BITMAP,pCB->GetAsHandle(CF_BITMAP),0);// ��������� �� ������
//     Form1->Canvas->Draw(0,0,Buffer);                 // �� � ��������, ����������
 //    Buffer->SaveToFile("kadr.bmp");                  // ��� � ���� ����������
//     ...                                            // ��� ��� ����
     pCB->Clear();                                    // ������� ����� ������
     delete Buffer;                                   // ����������� ������
*/
 hWndC=capCreateCaptureWindow("",WS_CHILD, this->Left, this->Top, this->Width, this->Height, this->Handle, 11011);
capDriverConnect (hWndC,0);

Timer2->Enabled=true;

}


}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
DBImage1->DoubleBuffered=true;
}
//---------------------------------------------------------------------------

