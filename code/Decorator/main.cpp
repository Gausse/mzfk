#include <iostream>
#include "classes.h"


int main()
{
    try
    {
        try
        {
            try
            {
                Exception* pEx = new Exception("Exception");
                throw pEx;
            }
            catch(Exception *pEx)
            {
                ChException *pCh = new ChException("ChException", pEx);
                throw pCh;
            }
        }
        catch(ChException *pCh)
        {
            GrChException *pGr = new GrChException("GrChException", pCh);
            throw pGr;
        }
    }
    catch (GrChException * pGr)
    {
        pGr->show();
        delete pGr;
    }

    return 0;
}

