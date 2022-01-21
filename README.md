<p align="center"><img src="https://socialify.git.ci/SkyfightTV/ArduinoChecker/image?description=1&amp;font=Bitter&amp;language=1&amp;pattern=Solid&amp;theme=Dark" alt="project-image"></p>

  
  
<h2>🧐 Features</h2>

Here're some of the project's best features:

*   Simply your code
*   Check easly your components

<h2>🛠️ Installation Steps:</h2>

<p>1. Download ArduinoChecker</p>

```
Download the project in .zip from the release page
```

<p>2. Import ArduinoChecker</p>

```
Import the file in .zip into ArduinoIDE
```

<p>3. Use ArduinoChecker</p>

```
Import  "AChecker.h" in your projet
```

<h2>🛠️ How to use ? :</h2>

<h3>Functions : </h3>

<ul>
  <li>Result check(TYPE type, int pin, bool debug)</li>
  <li>Result check(TYPE type, bool debug)</li>
  <li>Result check(TYPE type, int pin)</li>
  <li>Result check(TYPE type)</li>
</ul>

<h3>Enums :</h3>

<ul>
  <li>TYPE : 
    DHT_11,
    DHT_12,
    DHT_21,
    DHT_22,
    AM_2301,
    PHOTORESISTOR,
    CTN,
    RTC_CLOCK,
    POTENTIOMETER,
    SLIDE_SWITCH,
    INFRARED_SENSOR</li>
  <li>PIN_TYPE :
    ANALOG,
    DIGITAL,
    RTC</li>
  <li>RESULT_TYPE : <br>
    SUCCESS = HIGH,<br>
    FAILED = LOW,<br>
    PIN_NULL = LOW,<br>
    TYPE_NULL = LOW
</ul>

<h3>Return class :</h3>
<ul> 
  <li>RESULT_TYPE getResultType()</li>
  <li>PIN_TYPE getPinType()</li>
  <li>int getPin()</li>
  <li>TAB* getValues()</li>
  <ul>
    <li>unsigned long int size</li>
    <li>double *data</li>
  </ul>
</ul>

<h2>🛡️ License:</h2>

This project is licensed under the MIT
