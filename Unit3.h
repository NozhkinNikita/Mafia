//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class thrr : public TThread
{            
private:
protected:
        void __fastcall Execute();
public:
        __fastcall thrr(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
 