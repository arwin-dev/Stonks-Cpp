#include "smartCandlestick.h"

namespace Stonks_Cpp {
    smartCandlestick::smartCandlestick(String^ line) : candlestick(line)
    {
        Range = High - Low;
        BodyRange = Math::Abs(Close - Open);
        TopPrice = Math::Max(Open, Close);
        BottomPrice = Math::Min(Open, Close);
        TopTail = High - Math::Max(Open, Close);
        BottomTail = Math::Min(Open, Close) - Low;

        IsBullish = Close > Open;
        IsBearish = Open > Close;
        IsNeutral = BodyRange < (0.05 * Range);

        double lowerShadowRatio = static_cast<double>(Close - Low) / static_cast<double>(High - Low);
        double upperShadowRatio = static_cast<double>(High - Close) / static_cast<double>(High - Low);

        IsDoji = BodyRange <= (High - Low) * 0.05;
        IsMarubozu = (BodyRange / Range) >= 0.95;
        IsDragonFlyDoji = lowerShadowRatio >= 0.98 && upperShadowRatio < 0.02;
        IsGravestoneDoji = IsDoji && TopTail > (0.70 * Range);
        IsHammer = BottomTail > (High - Low) * 0.6 && TopTail < (High - Low) * 0.1;
        IsInvertedHammer = TopTail > (High - Low) * 0.6 && BottomTail < (High - Low) * 0.1;
    }
}