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

       bool capOK=capEditCopy(hWndC);       // копируем кадр в буфер обмена
  if (capOK) {


     TClipboard *pCB=Clipboard();                     // буфер обмена windows
     Graphics::TBitmap *Buffer=new Graphics::TBitmap; // сюда писать кадр будем
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
  capDriverConnect(hWndC,0);           // подключаемся к [первой] камере (тут загорается светодиод)
  capGrabFrame(hWndC);                 // дожидаемся и берём кадр с камеры
   bool capOK=capEditCopy(hWndC);       // копируем кадр в буфер обмена
  capDriverDisconnect(hWndC);          // отключаемся от камеры (тут светодиод гаснет)
  DestroyWindow(hWndC);                // убираем окно
  if (capOK) {                        // если всё получилось
     TClipboard *pCB=Clipboard();                     // буфер обмена windows
     Graphics::TBitmap *Buffer=new Graphics::TBitmap; // сюда писать кадр будем
     Buffer->LoadFromClipboardFormat(CF_BITMAP,pCB->GetAsHandle(CF_BITMAP),0);// считываем из буфера
//     Form1->Canvas->Draw(0,0,Buffer);                 // ну и например, показываем
 //    Buffer->SaveToFile("kadr.bmp");                  // или в файл записываем
//     ...                                            // или ещё чего
     pCB->Clear();                                    // очищаем буфер обмена
     delete Buffer;                                   // освобождаем память
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

