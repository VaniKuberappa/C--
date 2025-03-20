The process log data containing ad delivery data and
find aggregate statistics. An application called adserver records for each placement the banner
that was displayed and the price of the banner. Logs of this application look like the following

sel:6,ccd1ca23-e502-4ad6-9617-269b7d40cc4c,Banner-71,6.449
sel:6,ba101079-2729-4459-8e4f-6e2b902027fe,Banner-55,45.32
sel:6,8d783cf0-4435-4964-be5b-24b95aece7ab,Banner-6,33.848
sel:6,b1324a53-6915-47bf-8ee6-46e9ace57fc9,Banner-71,22.221
The format is the following:
"sel:" indicates the format of the the row
1st column: event id, 6 in this case means request
2nd column: request unique identifier - this is an id associated to each ad request
3rd column: the id of the banner it was delivered
4rd column: the price of the banner
Another application called adcounter counts if a certain banner was shown, the output of this
application is like the following
cnt:1,ccd1ca23-e502-4ad6-9617-269b7d40cc4c
cnt:114,ccd1ca23-e502-4ad6-9617-269b7d40cc4c
cnt:1,ba101079-2729-4459-8e4f-6e2b902027fe
cnt:114,ba101079-2729-4459-8e4f-6e2b902027fe
cnt:114,8d783cf0-4435-4964-be5b-24b95aece7ab
cnt:106,8d783cf0-4435-4964-be5b-24b95aece7ab
cnt:114,b1324a53-6915-47bf-8ee6-46e9ace57fc9
The format is the following
"cnt:" indicates the format of the row
1st column: event id - 1 means displayed, other values indicate other not better specified events
2nd column: the id of the request that the event refers to
The result of the aggregation tells you how many times an event happened for each banner and
what are revenues. Revenues are calculated only if the banner was displayed (event with id=1).
This is the result for the data above:

<Banners>
<Banner id="Banner-71" revenues="6.449">
<Events>
<Event id="6">2</event>
<Event id="1">1</event>
<Event id="114">2</event>
</Events>
</Banner>
<Banner id="Banner-55" revenues="45.32">
<Events>
<Event id="6">1</event>
<Event id="1">1</event>
<Event id="114">1</event>
</Events>
</Banner>
<Banner id="Banner-6" revenues="0">
<Events>
<Event id="6">1</event>
<Event id="106">1</event>
<Event id="114">1</event>
</Events>
</Banner>
</Banners>
This is a valid output when as the input you get the two snippets above. Herewith few additional
clarifications:
1. For Banner-71 you see that revenues are only 6.449 because for the second delivery
(request id b1324a53-6915-47bf-8ee6-46e9ace57fc9) there is no event with id=1
2. For Banner-6 there is no revenue because there was no event with id=1
The challenge consists in implementing a small Scala/Java /C++ application which, given an
input filename as a single argument, produces an XML similar to the one above.
The solution should contain:
- The resulting XML obtained by running your application on the data.log file included in
the tarball
- All source code and all instructions on how to build the application and run on data.log
- Unit tests
Please keep in mind that your solution should be correct, efficient, and minimal
