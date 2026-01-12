# Working Explanation

1. The soil moisture sensor measures the water content in soil.
2. The sensor outputs an analog value which is read by Arduino.
3. Arduino converts this value into a percentage using mapping logic.
4. If moisture level is below 30%, the relay turns ON the water pump.
5. If moisture level is above 30%, the relay turns OFF the pump.
6. The LCD displays:
   - Soil moisture percentage
   - Pump status (ON / OFF)

This system works automatically without human intervention and helps save water.
