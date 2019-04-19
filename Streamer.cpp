#include <vector>
#include "Streamer.hpp"

using namespace std;
 
 void Streamer::Trigger(vector<Rocket *> & v)
 {
	 Streamer *s = new Streamer;
	 v.push_back(s);
 }

 void DoubleStreamer::Trigger(vector<Rocket *> & v)
 {
	 DoubleStreamer *ds = new DoubleStreamer;
	 v.push_back(ds);
 }