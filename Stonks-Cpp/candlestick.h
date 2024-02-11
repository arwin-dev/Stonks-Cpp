#pragma once


namespace $safeprojectname$ {
    using namespace System;
    ref class candlestick
    {
        public:

            static array<String^>^ delimiter = { ",", " ", "\"" };
            static String^ dateFormat = "MMM dd, yyyy";

            property String^ ticker;
            property String^ period;
            property DateTime date;
            property double open;
            property double high;
            property double low;
            property double close;
            property unsigned long volume;

            candlestick(String^ line)
            {
                array<String^>^ fields = line->Split(delimiter, StringSplitOptions::RemoveEmptyEntries);
                ticker = fields[0];
                period = fields[1];
                String^ dateString = fields[2] + " " + fields[3] + ", " + fields[4];

                date = DateTime::Parse(dateString);
                open = Double::Parse(fields[5]);
                high = Double::Parse(fields[6]);
                low = Double::Parse(fields[7]);
                close = Double::Parse(fields[8]);
                volume = Int32::Parse(fields[9]);
            }
    };
}