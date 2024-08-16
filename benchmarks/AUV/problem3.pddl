(define (problem AUV-problem-5x5-1)
(:domain AUV)
(:objects 
l-1-1 l-2-1 l-3-1 l-4-1 l-5-1 l-1-2 l-2-2 l-3-2 l-4-2 l-5-2 l-1-3 l-2-3 l-3-3 l-4-3 l-5-3 l-1-4 l-2-4 l-3-4 l-4-4 l-5-4 l-1-5 l-2-5 l-3-5 l-4-5 l-5-5 - location
r1 r2 r3 r4 - resource
a1 a2 - auv
s1 - ship
)
(:init
(operational a1)
(at a1 l-1-1)
(operational a2)
(at a2 l-5-1)
(connected l-1-1 l-2-1)
(connected l-2-1 l-1-1)
(connected l-1-1 l-1-2)
(connected l-1-2 l-1-1)
(connected l-2-1 l-3-1)
(connected l-3-1 l-2-1)
(connected l-2-1 l-2-2)
(connected l-2-2 l-2-1)
(connected l-3-1 l-4-1)
(connected l-4-1 l-3-1)
(connected l-3-1 l-3-2)
(connected l-3-2 l-3-1)
(connected l-4-1 l-5-1)
(connected l-5-1 l-4-1)
(connected l-4-1 l-4-2)
(connected l-4-2 l-4-1)
(connected l-5-1 l-5-2)
(connected l-5-2 l-5-1)
(connected l-1-2 l-2-2)
(connected l-2-2 l-1-2)
(connected l-1-2 l-1-3)
(connected l-1-3 l-1-2)
(connected l-2-2 l-3-2)
(connected l-3-2 l-2-2)
(connected l-2-2 l-2-3)
(connected l-2-3 l-2-2)
(connected l-3-2 l-4-2)
(connected l-4-2 l-3-2)
(connected l-3-2 l-3-3)
(connected l-3-3 l-3-2)
(connected l-4-2 l-5-2)
(connected l-5-2 l-4-2)
(connected l-4-2 l-4-3)
(connected l-4-3 l-4-2)
(connected l-5-2 l-5-3)
(connected l-5-3 l-5-2)
(connected l-1-3 l-2-3)
(connected l-2-3 l-1-3)
(connected l-1-3 l-1-4)
(connected l-1-4 l-1-3)
(connected l-2-3 l-3-3)
(connected l-3-3 l-2-3)
(connected l-2-3 l-2-4)
(connected l-2-4 l-2-3)
(connected l-3-3 l-4-3)
(connected l-4-3 l-3-3)
(connected l-3-3 l-3-4)
(connected l-3-4 l-3-3)
(connected l-4-3 l-5-3)
(connected l-5-3 l-4-3)
(connected l-4-3 l-4-4)
(connected l-4-4 l-4-3)
(connected l-5-3 l-5-4)
(connected l-5-4 l-5-3)
(connected l-1-4 l-2-4)
(connected l-2-4 l-1-4)
(connected l-1-4 l-1-5)
(connected l-1-5 l-1-4)
(connected l-2-4 l-3-4)
(connected l-3-4 l-2-4)
(connected l-2-4 l-2-5)
(connected l-2-5 l-2-4)
(connected l-3-4 l-4-4)
(connected l-4-4 l-3-4)
(connected l-3-4 l-3-5)
(connected l-3-5 l-3-4)
(connected l-4-4 l-5-4)
(connected l-5-4 l-4-4)
(connected l-4-4 l-4-5)
(connected l-4-5 l-4-4)
(connected l-5-4 l-5-5)
(connected l-5-5 l-5-4)
(connected l-1-5 l-2-5)
(connected l-2-5 l-1-5)
(connected l-2-5 l-3-5)
(connected l-3-5 l-2-5)
(connected l-3-5 l-4-5)
(connected l-4-5 l-3-5)
(connected l-4-5 l-5-5)
(connected l-5-5 l-4-5)
(at-res r1 l-5-1)
(at-res r2 l-4-3)
(at-res r3 l-2-4)
(at-res r4 l-2-5)
(at s1 l-3-5)
(connected-ship s1 l-3-5 l-3-4)
(connected-ship s1 l-3-4 l-3-3)
(connected-ship s1 l-3-3 l-3-2)
(connected-ship s1 l-3-2 l-3-1)
(free l-2-1)
(free l-3-1)
(free l-4-1)
;(free l-5-1)
(free l-1-2)
(free l-2-2)
(free l-3-2)
(free l-4-2)
(free l-5-2)
(free l-1-3)
(free l-2-3)
(free l-3-3)
(free l-4-3)
(free l-5-3)
(free l-1-4)
(free l-2-4)
(free l-3-4)
(free l-4-4)
(free l-5-4)
(free l-1-5)
(free l-2-5)
;(free l-3-5)
(free l-4-5)
(free l-5-5)
)
(:goal
(and
(operational a1)(at a1 l-1-1)
(operational a2)(at a2 l-5-1)
(sampled r1)
(sampled r2)
(sampled r3)
(sampled r4)
)
)
)
