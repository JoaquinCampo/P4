# Overview
This C++ project, developed for the "Programación 4" course, is a language learning application designed to aid in mastering new languages through interactive exercises. It stands out for its application of various design patterns, enhancing the efficiency and maintainability of the codebase.

# Design Patterns
The project utilizes several key design patterns to optimize its architecture and functionality:

Singleton Pattern: Ensures that certain core components (like database connections or configuration managers) have only one instance throughout the application.
Factory Pattern: Used to create objects (like different types of exercises) without specifying the exact class of object that will be created, providing flexibility and scalability in object creation.
Observer Pattern: Allows for efficient updating and notification mechanisms, particularly useful in tracking user progress and course updates.
Model-View-Controller (MVC) Pattern: Separates the application into three interconnected components, enhancing scalability and maintainability. This is particularly useful for the UI layer, data management, and control logic.
