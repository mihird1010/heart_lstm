#include <FilterDerivative.h>
#include <FilterOnePole.h>
#include <Filters.h>
#include <FilterTwoPole.h>
#include <FloatDefine.h>
#include <RunningStatistics.h>
 
float reading;
float filteredreading;

void setup() {

  Serial.begin(9600);
  delay(3000);
  
}


// filter out frequencies below 1.5 Hz.
float highcutoff = 1.5;

// create a highpass filter that only keeps frequencies above highFilterFrequency
FilterOnePole filterOneHighpass( HIGHPASS, highcutoff );

// filters out frequenceies greater than 2 Hz.
float lowcutoff = 2;

// create a lowpass filter that only keeps frequencies below lowFilterFrequency
FilterOnePole filterOneLowpass(LOWPASS, lowcutoff);


void loop() {

      reading = 10 * analogRead(A0);
      filteredreading = filterOneHighpass.input(filterOneLowpass.input(reading));
      
      Serial.println(round(filteredreading/5));

      delay(50);


}
