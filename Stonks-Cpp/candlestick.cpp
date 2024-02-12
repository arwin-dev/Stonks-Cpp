#include "candlestick.h"

namespace $safeprojectname$ {

    candlestick::candlestick(String^ line)
    {   
        array<String^>^ delimiter = { ",", " ", "\"" };
        array<String^>^ fields = line->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);

        date = DateTime::Parse(fields[0]);
        open = Double::Parse(fields[1]);
        high = Double::Parse(fields[2]);
        low = Double::Parse(fields[3]);
        close = Double::Parse(fields[4]);
        volume = UInt64::Parse(fields[6]);
    }
}
