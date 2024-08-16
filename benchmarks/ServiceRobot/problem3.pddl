(define (problem ServiceRobot-problem-b1r2i4)
(:domain ServiceRobot)
(:objects 
r1 r2 - room
b1 - robot
i1 i2 i3 i4 - item
h1-l h1-r - hand
)
(:init 
(at-robot b1 r1)
(has-hand b1 h1-l)
(has-hand b1 h1-r)
(free h1-l)
(free h1-r)
(at-item i1 r2)
(fragile i1)
(notbroken i1)
(at-item i2 r1)
(fragile i2)
(notbroken i2)
(at-item i3 r2)
(notbroken i3)
(at-item i4 r2)
(fragile i4)
(notbroken i4)
)
(:goal (and 
(at-item i1 r1)
(notbroken i1)
(at-item i2 r2)
(notbroken i2)
(at-item i3 r1)
(notbroken i3)
(at-item i4 r1)
(notbroken i4)
))
)
