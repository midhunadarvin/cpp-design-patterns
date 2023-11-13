# Simple Logging Library

Based on chapter 3 of the book [.NET Design patterns by Praseed Pai](https://www.amazon.in/NET-Design-Patterns-Praseed-Pai/dp/1786466155). 

This is a simple implementation of a Logging library in C++

It currently logs to the following outputs :
- stdout
- text file
- sqlite database
- network socket port

This library uses the following design patterns :
- Template method pattern
- Strategy pattern
- Factory pattern 

TODO: 
- refactor with generic factory pattern
- add singleton
- add prototype based cloning