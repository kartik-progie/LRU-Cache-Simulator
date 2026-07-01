# LRU Cache Simulator
Ever wondered how your phone or computer remembers recently used apps so they open faster the next time? I built a simplified version of that system — it's called a 'cache.'
The problem I am solving here is that computer have two types of memory , a smaller one for very fast tasks and decision making and a larger one which is slower. Faster memory holds the recently done tasks and keep them open but as said earlier it is small so it has to be cleaned up in reak time, and i achieve that by two different methods:
1) By implementing LRU which removes whatever hasn't been used the longest , like we toss out things from the fridge which we haven't touched in weeks.
2) By implementing LFU which removes whatever which has been least frequently used overall - even if it is the last thing which was used, like getting rid of a kitchen gadget even if we have used it yesterday.

I made sure that both these decisions happen simultaneously and system always knows what to throw rather than search for it , no matter how much data is being managed by it.
Then i tested both strategies in different realistic usage patterns to see which one works better where and then built charts to visualise the results.

A C++ implementation of the Least Recently Used (LRU) Cache using:

- Doubly Linked List
- Hash Map
- OOP concepts

----------------------------------------INCOMPLETE--------------------------------------------------------------------------------
LFU CODE NOT ADDED YET
GRAPHS AND CHARTS NOT EXPLAINED YET
NOTHING ABOUT REAL WORLD WORKLOAD
BASICALLY THE LAST TWO POINTS OF THE PROJECT IS STILL INCOMPLETE
