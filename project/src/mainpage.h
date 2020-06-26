/*! \mainpage My Personal Index Page
 *
 * \section intro_sec Introduction
 *
 * This project simulates bus routes along the U of M campus.
 * 
 * Routes can be set using the config.txt file in the config folder. Follow the templates given, making sure the Inbound route starts at the same stop that the Outbound route does and vice versa.
 * 
 * To compile, navigate to the project/src/ directory and run the following commands:
 * 
 *      make
 * 
 *      cd ..
 * 
 *      ./build/bin/vis_sim <port_number>
 * 
 * where port_number is any port above 8000. Then open http://127.0.0.1:<port_number>/web_graphics/project.html in a browser, and the simulation will be there.
 * 
 * \section Factories
 * 
 * There were 2 possible ways I could've implemented factories: concrete and abstract. A concrete factory design would entail making one singular factory class, which would receive a bus type and produce a bus of that size. An abstract factory design would entail creating an interface that is followed by separate factories for each bus size. This interface would require the factories to have a GenerateBus class which is unique to each factory, depending on the size of the bus. 
 * 
 * I chose to implement the abstract version. The abstract factory implementation is better because it is more open to expansion. However, the downside is that it is more difficult to implement. On the other hand, concrete factories are easier to implement, but they are much harder to expand upon.
 * 
 * \section Observer Designing and Implementing the Observer Pattern
 * 
 * To create an observer pattern in the project, I needed to build a few classes. These were the IObserver and ISubject classes. The ISubject class allowed me to turn each bus into an observable object, with the ability to attach, detach, and notify observers. The IObserver class is an abstract class that ensures that each observer can Notify() and display information on the screen. In addition, I had to modify the Bus class so that a) it's defined as an ISubject and b) it now notifies its observers whenever it moves.
 * 
 * Using the given code, I defined the BusWebObserver class within the MyWebServerCommand class as an implementation of an IObserver. This made sure that when the observer was told to Notify by the bus, it knew what to output on the screen. The code also defined the AddListenerCommand, which triggered that hardest part of the implementation, creating the VisualizationSimulator method AddListener.
 * 
 * The AddListener method is called by the AddListenerCommand and attaches the BusWebObserver to the bus. The hard part was sorting through all the types of parameters of the method, both pointers and not, to try and make it match the provided UML diagram for the pattern. Then I had to figure out how to find the correct bus and correctly attach the observer to it.
 * 
 * In the end, sketch.js sees the click of the mouse and tells main.cpp, which calls AddListenerCommand. AddListenerCommand clears all listeners, then tells VisualizationSimulator to add a new BusWebObserver onto whichever bus was clicked on. VisualizationSimulator then attaches the observer onto the bus, and whenever the bus moves, it runs Notify(), which displays the bus's information onto the screen.
 *  
 * 
 * \section Decorator Designing and Implementing the Decorator Pattern
 * There were two decorator designs that I could choose to implement: a single BusDecorator class, or a BusDecorator class that is inherited by multiple specific decorators underneath it. These two designs basically mirror the design principle of concrete and abstract classes, respectively, and will be referred to as such for the rest of this discussion. The concrete design would entail creating a single BusDecorator class, which would decorate all facets of the bus within the single class. The abstract design would entail a mostly empty BusDecorator class, while the real decoration was happening in the children of that class. Each individual child would control a different decoration facet: which color, color intensity, and so on.
 * 
 * I chose to implement the 'concrete' design. This design is easier to implement, as fewer classes are involved and the design part of the implementation is very straightforward. From a design focused standpoint, this design is very bad. It has low cohesion and high coupling - all of the power of the decorator is held within the one class and that class is tasked with carrying out the entirety of the decorating. It's also open to change and closed to expansion - any adjustment to the decoration would mean changing maybe the entire class, and must be done within that class.
 * 
 * The 'abstract' design is much more appealing to the design side of programming. It is everything that the concrete design isn't, in a good way. If this were a real-world project that had a future beyond this semester, this is the design I would implement. Its drawback is that it is harder to write code for, which is the only criteria that matters in this instance. The abstract design has high cohesion - each specific decorator does only one decoration. It has low coupling - two decorators are entirely unrelated to each other. It's closed to change - only one decorator has to be changed at a time. Finally, the abstract design is open to extension - adding a new decorator only affects the one being added. 
 */
