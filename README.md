# Arduino pH Sensor

Reading a pH sensor using mathematical formulas requires. First obtaining ADC data from the pH sensor, such as readings for acidic, basic, and neutral solutions. Once these readings are collected, the average can be calculated and then used in the mathematical formula.

<code>slope = ( (pHBase - pHNeutral) / (avgAnalogValueBase - avgAnalogValueNeutral) + (pHNeutral - pHAcid) / (avgAnalogValueNeutral - avgAnalogValueAcid) ) / 2;
intercept = pHNeutral - (slope * avgAnalogValueNeutral);
</code>
