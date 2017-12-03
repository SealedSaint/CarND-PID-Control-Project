Project Reflection

First, I was really impressed by the small amount of code necessary to get a car driving around a
simulated track! Overall, PID controllers seem very powerful, but they also seem very sensitive to
the hyperparameter choices.

I thought Sebastian's explanation of the P, I, and D potions of a PID controller were very
straightforward and easy to understand, but as I got into hyperparameter tuning it became
apparent that I didn't understand things quite as well as I thought.

P in PID

I feel like I have a really good grasp of this portion of the PID controller. I felt like I
understood it from the beginning and my experience with the project just confirmed my initial
understanding (unlike the other two portions).

If I had to put the "Proportional" part of the controller into my own words, I would describe it
as such: the P portion determines how quickly and adamantly your controller will try to get back
to the set-point.

When I was tuning hyperparameters I thought it was pretty clear (at least compared to the other
portions) when this parameter needed tweaking. When the car just wasn't correcting itself fast
enough (especially for turns), I upped this parameter, and it almost always seemed to help.

D in PID

The D portion of the controller was probably the one I feel like I mis-understand the greatest.
Originally I would have described the D portion as: increase the D parameter to prevent
over-correcting. This was clearly too narrow of an understanding though, because as I
experimented with the hyperparameters sometimes increasing D too much caused wild over-corrections!
Perhaps this is because too high of a D param limits the P value too much.

If I had to put the role of the D term in my own words now, I would say something like: increasing
the D param means the more you've been changing the less you change. I feel like that's an
accurate view of the D param now, but understanding and internalizing that meaning
for the purpose of tuning is a harder task.

I in PID

The "I" portion of the PID controller worked about how I expected after watching the lessons.
In my own words: An increased "I" parameter
means your controller will correct over-time mistakes (biases) quicker. While I feel like that is
accurate, it was hard to tweak the param correctly.

At first I would tweak the param so that total error was always reduced to zero fairly quickly
after being accumulated. However, I found that an "I" param value high enough to accomplish
this often over-powered the P param (causing loss of priority on turns, for example). It also
made for unpleasant-looking, jerky driving.

I ended up using a lower "I" value with my final solution, but this meant that sometimes total error
accumulated more than I would like and took a long time to drop back to zero - especially at higher
speeds.

Choosing Hyperparameters

I decided to manually tweak the hyperparameters. This was partly by intention and partly by
accident. I first started playing with the hyperparameters manually to get a feel for how they
worked and affected the car. I'm glad I did, because as mentioned above this led to some additional
understanding and identified gaps in my knowledge.

After manually tweaking for a while I felt a bit invested in the process and just decided to
continue on. I considered implementing a twiddle algorithm from some initial decent params that
I manually found, but the time/reward trade-off just didn't seem worth it given that I wasn't sure
how to implement twiddle while using the simulator.

I ended up choosing the following parameters (P, D, I): (0.12, 0.005, 0.0005)

Some Other Things I Learned

I also learned the difference between relative param values (to each other) and absolute param
values. I was initially surprised to learn that as long as the params were scaled appropriately
relative to one other the controller would perform about the same. This was a neat find and helped
the tuning process.

I discovered later that absolute values of the parameters is still important, though. This
became apparent to me as I tried increasing the speed of the car. High speeds resulted in a need
for lower param values, I found. While I'm not sure how accurate this view is, I reasoned that
higher speeds meant a need for more precisely tuned param values to account for the lack of
correction time. High steering angles at high speeds cause more change per second than high
steering angles at low speeds. High speeds call for small tweaks, not large ones.
