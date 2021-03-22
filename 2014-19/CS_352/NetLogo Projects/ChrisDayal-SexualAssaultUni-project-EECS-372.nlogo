extensions [table]

globals [bar school park frat assault-place-count]

turtles-own [
  dict
education? ;; education personality variable that is able to be manipulated.
sex ;; to designate male and female interactions and procedures.
year ;; variable to give turtle respective weight depending on what year of school they are in. the younger a turtle, the more susceptible as a perpetrator and victim.
year-weight ;; 1,2,3,4 correlating with the years of undergraduate for purpose as mentioned above
personality ;; implemented to give turtle university student like personality in terms of preferences and where to interact.
personality-var ;; allows the turtle to move intelligbly whilst being random due to the desire to fulfill a personal longing.
;;For example, if a turtle who likes to go to the fraternity a lot does not for a while, he will want to go and fulfill his desire. Enhances randomness and simulates student mindsets.
]

links-own [
 no-of-interactions-girl
 ;;implemented to track how many times female turtles interact with male turtles due to statistics iterating females have interacted with
 ;;their victim almsot 80% of the time. Again, implemented to mirror real like reference pattern. Create the interactions to be as accurate as possible.
]

to setup
  clear-all ;; clear all existing agents
  set bar patches with [pxcor < 0.5 and pycor > -1] ;; initializes patch-sets that are referred to throughout. Creating them like this makes it a lot easier to reference the enviornments.
  ask bar [set pcolor yellow + 2.5]                 ;; Cleans up the code from below.
  set frat patches with [pxcor > 0.5 and pycor > 0]
  ask frat [set pcolor black]
  set school patches with [pxcor <= 0.5 and pycor < 0]
  ask school [set pcolor white]
  set park patches with [pxcor > 0.5 and pycor < 0]
  ask park [set pcolor green + 2.5]
  set assault-place-count []


  ;ask patches
  ;[;;if pxcor <= 0.5 and pycor < 0 [set pcolor white] ;;old code that was orignally used to demarcate the world.
    ;if pxcor > 0.5 and pycor < 0 [set pcolor green + 2.5]
    ;if pxcor < 0.5 and pycor > -1 [set pcolor yellow + 2.5]]

  set-default-shape turtles "person" ;; defines the turtle shape that will be used. People to represent people.

  create-turtles men  [ ;; slider variable men that adjusts how many men turtles are made
    set sex 0 ;;sets their sex variable to 0 so that they can be distinguished from women.
    setxy random-xcor random-ycor ;;distributes the turtles throughout the world randomly
    set size 1 ;;visually pleasing.
    ]

  create-turtles women  [ ;; slider variable women that adjusts how many women are made
    set sex 1 ;;sets their sex variable to 1 so that they can be distinguished from men.
    setxy random-xcor random-ycor ;;distributes the turtles throughout the world randomly
    set size 1 ;;visually pleasing.
    ]

  ask turtles [
    set dict table:make ;;dictionary that is used to store and keep track of turtle who numbers and subsequent multiple interactons amongst male and female turtles.
    set personality one-of [1 2 3 4] ;;randomly assigns turtles to one of 4 personality types for intelligence and personality. Iterates real life desires and phenomeona.
    ifelse sex = 0 ;; used to color the agents appropiately depending on what year of studies they are in, Light pink to dark pink for females starting from freshman all the way to seniors.
        [set year one-of [1 2 3 4]] ;; light blue to dark blue for all male turtles indicating freshmen all the way to seniors.
        [set year one-of [5 6 7 8]]


      ]
  color-year ;;colors the turtles accordingly.
  vulnerability ;;sets year-weights to respective turtles. takes into account the statistic that younger people are more prone to be perpetrators or victims.
reset-ticks ;; resets counter
end


to go ;; go function for interaction
  ;ask links [hide-link]
  ask turtles [
    move ;; moves turtles somewhat randomly whilst taking into account their personality.
   ; hostileinteraction] ;; intitial funciton that was used for turtle interaction
  interactfrat ;;interaction procedure unique to relatively statistical replicate prevailing traits and characteristics of sexual assault in a fraternity enviornment.
  interactbar ;;interaction procedure unique to relatively statistical replicate prevailing traits and characteristics of sexual assault in a bar like enviornment.
  interactpark ;;interaction procedure unique to relatively statistical replicate prevailing traits and characteristics of sexual assault in a park enviornment.
  interactschool ;;interaction procedure unique to relatively statistical replicate prevailing traits and characteristics of sexual assault in school enviornment.
  personality-need
  ];; variable that dictates a turtle moving to its personality niche depending on their threshold value.

  tick;;occurs per tick.
end



to color-year ;; used this list to color the turtles based on their gender and years.
  ask turtles[
     if sex = 0 [
       if year = 1 [set color 108] ;; light blue (freshman male)
       if year = 2 [set color 107] ;; sophomore male
       if year = 3 [set color 106] ;; junior male
       if year = 4 [set color 105]];; dark blue (senior male)
     if sex = 1 [
       if year = 5 [set color 138] ;;light pink (freshman female)
       if year = 6 [set color 137] ;;sophomore female
       if year = 7 [set color 136] ;;junior female
       if year = 8 [set color 135]]];;dark pink (senior female)
end




to personalityinitial ;;sets the original personality variable to 100. This fluctuates and dictates a turtles movement as turtles move away and from their niche.
  ask turtles [ set personality-var 100 ]
  end


to personality-need ;;creates 4 personality types depending on the 4 enviornment types in the world. Each personality has a preference to an enviornment.
  if personality = 1 [
    ifelse patch-here = one-of bar
      [set personality-var personality-var + 20]
      [set personality-var personality-var - .05]]
  if personality = 2 [
    ifelse patch-here = one-of frat
      [set personality-var personality-var + 20]
      [set personality-var personality-var - .05]]
  if personality = 3 [
    ifelse patch-here = one-of school
      [set personality-var personality-var + 20]
      [set personality-var personality-var - .05]]
  if personality = 4 [
    ifelse patch-here = one-of park
      [set personality-var personality-var + 20]
      [set personality-var personality-var - .05]]
end


to vulnerability ;; playing with weight variables here for status in undergrad and possibility of being / perpotrating sexual assault.
  ask turtles[
      if sex = 0 [
       if year = 1 [set year-weight 4] ;; statistically based off of the fact that latter years decrease significantly in perpetrating or becoming a victim of assault (4 times less)
       if year = 2 [set year-weight 4]
       if year = 3 [set year-weight 1]
       if year = 4 [set year-weight .8]]
      if sex = 1 [
       if year = 5 [set year-weight 4]
       if year = 6 [set year-weight 4]
       if year = 7 [set year-weight 1]
       if year = 8 [set year-weight .8]]]
  end

to move ;; moves function for turtles. if the value is less than the defined threshold, the turtle will move towards its desired patch based on its personality type.
        ;; Allows for intelligence and personality types in agents and behavior.
    if personality = 1 [
      ifelse personality-var <= 0
       [face one-of bar
         fd 1]
         [rt random 90
           lt random 90
           fd 1]]
    if personality = 2 [
      ifelse personality-var <= 0
      [face one-of frat
        fd 1]
      [rt random 90
        lt random 90
        fd 1]]
    if personality = 3 [
      ifelse personality-var <= 0
      [face one-of school
         fd 1]
      [rt random 90
        lt random 90
        fd 1]]
    if personality = 4 [
      ifelse personality-var <= 0
      [face one-of park
         fd 1]
      [rt random 90
        lt random 90
        fd 1]]
end



to assault
  set color red
  set assault-place-count fput pcolor assault-place-count
end



to interactfrat ;; probability that sexual assault occurs based on relative weights derived from
                ;;statistically supported research that indicates prevailing sexual assault causes/characteristics in this enviornment as defined in paper.
    if pcolor = black [
      if sex = 0 [
        let target one-of turtles in-radius 3
          ifelse (table:has-key? dict ([who] of target)) [ ;; turtle checks in dictionary to see if the who number of the target within the radius is present, the number of target interactions is represented by the
            ;; notargetinteractions variable. it then takes the past interaction of the turtles and factors it into the probabililty of a female turtle being assaulted.
            let notargetinteractions (table:get dict ([who] of target))
            ask target [
              let awareness education?
              if (sex = 1 and random-float 10 < ((.4 * notargetinteractions) + (hostility * .4) + (alcohol * .8) - (empathy * .2) - (awareness * 2 * .45) + (year-weight)))
          [assault]]
            table:put dict [who] of target table:get dict [who] of target + 1]
          [table:put dict [who] of target 1
            ]]]
end



to interactbar ;; probability that sexual assault occurs based on relative weights derived from
                ;;statistically supported research that indicates prevailing sexual assault causes/characteristics in this enviornment as defined in paper.
    if pcolor = yellow + 2.5 [
      if sex = 0 [
        let target one-of turtles in-radius 3
          ifelse (table:has-key? dict ([who] of target)) [ ;; turtle checks in dictionary to see if the who number of the target within the radius is present, the number of target interactions is represented by the
            ;; notargetinteractions variable. it then takes the past interaction of the turtles and factors it into the probabililty of a female turtle being assaulted.
            let notargetinteractions (table:get dict ([who] of target))
            ask target [
              let awareness education?
              if (sex = 1 and random-float 10 < ((.20 * notargetinteractions) + (hostility * .2) + (alcohol * .8) - (empathy * .2) - (awareness * 2 * .45) + (year-weight)))
          [assault]]
            table:put dict [who] of target table:get dict [who] of target + 1]
          [table:put dict [who] of target 1
            ]]]
end



to interactpark ;; probability that sexual assault occurs based on relative weights derived from
                ;;statistically supported research that indicates prevailing sexual assault causes/characteristics in this enviornment as defined in paper.
    if pcolor = green + 2.5 [
      if sex = 0 [
        let target one-of turtles in-radius 3
          ifelse (table:has-key? dict ([who] of target)) [ ;; turtle checks in dictionary to see if the who number of the target within the radius is present, the number of target interactions is represented by the
            ;; notargetinteractions variable. it then takes the past interaction of the turtles and factors it into the probabililty of a female turtle being assaulted.
            let notargetinteractions (table:get dict ([who] of target))
            ask target [
              let awareness education?
              if (sex = 1 and random-float 10 < ((.15 * notargetinteractions) + (hostility * .1) + (alcohol * .2) - (empathy * .4) - (awareness * 2 * .45) + (year-weight)))
          [assault]]
            table:put dict [who] of target table:get dict [who] of target + 1]
          [table:put dict [who] of target 1
            ]]]
end




to interactschool ;; probability that sexual assault occurs based on relative weights derived from
                ;;statistically supported research that indicates prevailing sexual assault causes/characteristics in this enviornment as defined in paper.
    if pcolor = white [
      if sex = 0 [
        let target one-of turtles in-radius 3
          ifelse (table:has-key? dict ([who] of target)) [ ;; turtle checks in dictionary to see if the who number of the target within the radius is present, the number of target interactions is represented by the
            ;; notargetinteractions variable. it then takes the past interaction of the turtles and factors it into the probabililty of a female turtle being assaulted.
            let notargetinteractions (table:get dict ([who] of target))
            ask target [
              let awareness education?
              if (sex = 1 and random-float 10 < ((.15 * notargetinteractions) + (hostility * .1) + (alcohol * 0) - (empathy * .4) - (awareness * 2 * .45) + (year-weight)))
          [assault]]
            table:put dict [who] of target table:get dict [who] of target + 1]
          [table:put dict [who] of target 1
            ]]]
end







;;;;;;;;
;old functions that were used to compute probability without taking into account past interactions. Just so you can see the mental process I engaged in as I developed the model and
;shaped it to mirror real life phenomena.
;;;;;;;;

;to interactbar ;; probability that sexual assault occurs based on relative weights derived from
                ;;statistically supported research that indicates prevailing sexual assault causes/characteristics in this enviornment as defined in paper.
 ;   if pcolor = yellow + 2.5 [
  ;    if sex = 0 [
   ;     let target one-of turtles in-radius 3
    ;    ask target [ let awareness education?
     ;     if (sex = 1 and random-float 10 < ((hostility * .002) + (alcohol * .008) - (empathy * .002) - (awareness * 2 * .40) + (year-weight)))
      ;    [assault]]]]
;end


;to interactpark ;; probability that sexual assault occurs based on relative weights derived from
 ;               ;;statistically supported research that indicates prevailing sexual assault causes/characteristics in this enviornment as defined in paper.
  ;  if pcolor = green + 2.5 [
   ;   if sex = 0 [
    ;    let target one-of turtles in-radius 3
     ;   ask target [ let awareness education?
      ;    if (sex = 1 and random-float 10 < ((hostility * .001) + (alcohol * .002) - (empathy * .004) - (awareness * 2 * .40) + (year-weight)))
    ;      [assault]]]]
;end



;to interactschool ;; probability that sexual assault occurs based on relative weights derived from
 ;                 ;;statistically supported research that indicates prevailing sexual assault causes/characteristics in this enviornment as defined in paper.
  ;  if pcolor = white [
   ;   if sex = 0 [
    ;    let target one-of turtles in-radius 3
     ;   ask target [ let awareness education?
      ;    if (sex = 1 and random-float 10 < ((hostility * .001) + (alcohol * 0) - (empathy * .004) - (awareness * 2 * .40) + (year-weight)))
       ;   [assault]]]]
;end




;to hostileinteraction ;; probability that sexual assault is ar result in male hosility,alcohol intoxication, empathy, and awarness. ORIGINAL procedure that was developed and improved.
 ;if sex = 0 [
  ;let target one-of turtles in-radius 3
   ;ask target [ let awareness education?
    ;if (sex = 1 and random-float 10 < ((hostility * .001) + (alcohol * .008) - (empathy * .002) - (awareness * 2 * .30)))
     ;[set color red]]]
;end


;; This was the original function that I was working on implementing to track past turtle interaction and ultimately use to influence future interactions of other turtles given the
;; role of multiple prior interactions between female victims of sexual assault to males..
to go-and-count1
  ask turtles [
    if sex = 1 [
      fd 1
      if any? other turtles-here with [sex != 1] [
        ask one-of other turtles-here with [sex != 1] [
          ask link who [who] of myself [set no-of-interactions-girl no-of-interactions-girl + 1]]
          ]]]
 end
@#$#@#$#@
GRAPHICS-WINDOW
210
10
649
470
16
16
13.0
1
10
1
1
1
0
0
0
1
-16
16
-16
16
0
0
1
ticks
30.0

SLIDER
4
21
176
54
men
men
0
100
100
2
1
NIL
HORIZONTAL

SLIDER
3
81
175
114
women
women
0
100
100
2
1
NIL
HORIZONTAL

BUTTON
10
136
76
169
NIL
setup\n
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
102
137
165
170
NIL
go\n
T
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

SWITCH
36
399
139
432
ses
ses
0
1
-1000

SLIDER
2
231
174
264
hostility
hostility
0
10
0
1
1
NIL
HORIZONTAL

SLIDER
3
286
175
319
empathy
empathy
0
10
10
1
1
NIL
HORIZONTAL

SLIDER
5
341
177
374
education
education
0
10
10
1
1
NIL
HORIZONTAL

SLIDER
8
448
180
481
alcohol
alcohol
0
10
0
1
1
NIL
HORIZONTAL

PLOT
671
10
871
160
Assaulted Turtles Total
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"Assaulted" 1.0 0 -16777216 true "" "plot count turtles with [color = red]"

PLOT
671
181
871
331
Freshman Assaulted
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"freshmen" 1.0 0 -16777216 true "" "plot count turtles with [color = 138]"

BUTTON
51
180
132
213
go once
go
NIL
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

BUTTON
6
610
229
643
past-interaction-mapping-test
go-and-count1
T
1
T
OBSERVER
NIL
NIL
NIL
NIL
1

PLOT
893
180
1093
330
Sophomores Assaulted
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"sophomores" 1.0 0 -16777216 true "" "plot count turtles with [color = 137]"

PLOT
671
354
871
504
Juniors Assaulted
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"juniors" 1.0 0 -16777216 true "" "plot count turtles with [color = 136]"

PLOT
894
354
1094
504
Seniors Assaulted
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"seniors" 1.0 0 -16777216 true "" "plot count turtles with [color = 135]"

PLOT
892
10
1092
160
Comparative Assaults by Year of Study
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"" ""
PENS
"Freshmen" 1.0 0 -5298144 true "" "plot count turtles with [color = 138]"
"Sophomores" 1.0 0 -3844592 true "" "plot count turtles with [color = 137]"
"Juniors" 1.0 0 -10402772 true "" "plot count turtles with [color = 136]"
"Seniors" 1.0 0 -4079321 true "" "plot count turtles with [color = 135]"

PLOT
1108
49
1388
244
Line Graph of Assaults by Location
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"set-plot-x-range 0 60" ""
PENS
"Assault" 1.0 0 -2674135 true "" "histogram assault-place-count"

TEXTBOX
1155
251
1230
269
Frat   School
11
0.0
1

TEXTBOX
1334
251
1484
269
Bar     Park
11
0.0
1

PLOT
1112
270
1389
470
Histogram of Assauls by Location
NIL
NIL
0.0
10.0
0.0
10.0
true
false
"set-plot-x-range 0 60" ""
PENS
"default" 1.0 1 -13345367 true "" "histogram assault-place-count"

@#$#@#$#@
## WHAT IS IT?

This model attempts to simulate sexual assault given statistically defined characteristics in certain environrments through a small isolated human population. It attempts to illustrate the positive effects of certain educational and empathy building policies to address the growing university problem.

It is known that sexual assault is a growing problem on university campuses all over the
world. The statistics iterate that young first year or second year women are particular at target. Overall, 25% of women are thought to experience assault during their college years. In additoin to this, 60% of women generally choose not to tell anyone. University culture consists of heavy drinking, relative male hostility through fraternities, lack of sexual prevention education, and subjective empathy. Based on different enviornments that unversity students tend to interact in, this model focuses only on the sexual assault given the relatively similar characteristics of sexual assault cases in the respective environments.

This model examines the emergent effects with respect to 4 enviornments. These enviornments consist of bars, fraternities, school, and parks or open space.

The user controls the population with respect to females and males. The user can also control the impact of the characteristic traits to observe trends within the enviornment.
Exploration of efforts or prevalence in educational prevention programs and empathy can exemplify how changes in policy can affect the rate of sexual assault, while observing the effects of lacks of policy.

By allowing the user to control the different characteristic traits of sexual assault as mentioned in literature, and efforts to combat the epdiemic, users can varying effects.

how often an average individual will choose to be tested, the user can explore an important dimension of HIV's threat to public health.  Because the virus does not make itself immediately known in its host, individuals are often infected for some time before a test or immune deficiency symptoms (which leads to a test) identifies them as such.  Regular identification of individuals infected by the virus could have significant public health impacts if knowledge of the infection positively affected sexual behaviors.  This model explores this possibility by making all individuals who know of their positive HIV status always practice safe sex.

## HOW IT WORKS

(what rules the agents use to create the overall behavior of the model)

The model uses males and females to represent interactions.  Individuals are given personality characteristics (1/4 each preferred to a different enviornment). Individuals wander around the world fulfilling personality needs and interacting with females.  Upon coming into radius with a suitable partner, there is a chance the female will be assaulted depending on the enviornment (characeristic traits in respect to sexual assault cases in these enviornmetns differ probabilites). For example, alcohol may highly influence assault in a bar wheras in a school it may not have an effect at all.  When assault occurs, the assaulted female turns red.

The differences in the age of the population is represented by the colors of individuals. There are 4 colors used for each males and females. The older the male, the darker their tint of blue is. Freshmen thus are lightest blue and seniors the darkest. The same idea applies for females in respect to pink. The darker the pink, the older the female and the lighter the pink the younger she is. Freshmen females thus are the lightest pink and Seniors are depicted as dark pink. Red indicates that a female has been assaulted.

## HOW TO USE IT

The SETUP button creates individuals with particular behavioral personalities.  Patcehs are also set up with probability of assault tendencies given statistical literature supporting the role of specific factors in given enviornments. Accourding to the value of interface's five sliders, one can adjust the levels of traits (hostility, empathy, education, alcohol) to see differences in assault patterns.  Once the simulation has been setup, you are now ready to run it, by pushing the GO button.  GO then starts the simulation and runs it continuously until GO is pushed again.  During a simulation initiated by GO, adjustments in sliders can affect the behavioral tendencies of the population. To observe full impacts, press SETUP again and observe from the beginning.

Monitors show the population that is assaulted by age and location (patch-area/enviornme nt).


Here is a summary of the sliders in the model.  They are explained in more detail below.

- men: How many men simulation begins with.
- women: How many women simulation begins with.
- hostility: General level of how impactful hosility that is taken into account for assault (0--10).
- alcohol: General level of how impactful alcohol that is taken into account for assault (0--10).
- empathy: General level of how impactful empathy intervention that is taken into account for assault (0--10).
- education: General level of how impactful educational prevention intervention that is taken into account for assault (0--10).

The total number of individuals in the simulation is controlled by the slider men and women (initialized to vary between 0--100), which must be set before SETUP is pushed.

During the model's setup procedures, all patches are given probabilities for assault according to four additional sliders and statistical weights of characteristic traits of sexual assault.

The slider hostility (0--10) determines the impact of hostile behavior of the male turtles in assaulting the female turtles. When the hostility slider is set at zero, assault is at baseline, although (because probailities are chance) assault is still possible.

The slider alcohol determines how much of a role alcohol plays in assault given the enviornmental sexual assault characteristic probabilities.  Again, the tendencies of both individuals in a relationship are considered; the relationship only lasts as long as is allowed by the tendency of the partner with a shorter commitment tendency. When the alcohol slider is set at zero, assault is at baseline, although (because probailities are chance) assault is still possible.

The slider empathy (0--10) determines the level of empathy that is factored in a males probability to assault.  If a higher empathy is indicated, it should be apparent that assault in respect to the female population is largely elongated due to the fact that empathy has a statistically proven positive effect in mitigating sexual assault.

The slider education (0--10) is the final slider of the interface.  It determines the determines the level of education that is factored in a males probability to assault. Education has a statistically effective rate (almost 50%) in mitigating assault. If a higher rate of education intervention is indicated, it should be apparent that assault in respect to the female population is largely elongated due to the effect of education on assault.


The model's plot shows the total number females assaulted, females assaulted by age, and various locations of assaults.


## THINGS TO NOTICE

(suggested things for the user to notice while running the model)

Play with the intial men and women population to oberve the rates of asault when there are both fewer men than women and vice versa.

Adjust the characteristic traits of sexual assault to see how quickly rates increase in freshmen and sophomores, more quickly than the other populations.

Adjust hosility to observe the locations of where most assaults take place. Do this same thing with education and empathy and you can see some clear trends.

The overall rate of assault amongst females and their locations is deeply effected by increasing instigators of sexual assault and are intersingly affected whilst observing the impact of certain preventative measueres.






## THINGS TO TRY

(suggested things for the user to try to do (move sliders, switches, etc.) with the model)


Run some experiments with the GO button to find out the effects of different variables on assault with respect to females. At what rate is abuse in the female turtles affected with full educational programmes?

Are the effects of some mitigating slider variables to sexual assault mediated by the effects of others? What are the best measures to best decrease rates of sexual assault.

## EXTENDING THE MODEL

Much like all computer simulations of human behaviors, this model has necessarily simplified its subject area substantially.  The model therefore provides numerous opportunities for extension:

Perhaps the implementation of more personality based traits amongst females.

Introduction of more intelligent agent behavior (females looking out for each other to resemble the buddy system)

The effect of socioeconomic status and poverty to sexual assault.

Allow repeated instances of assault to observe traits that are difficult to address. This can help create more well rounded prevention strategies.


## NETLOGO FEATURES

(interesting or unusual features of NetLogo that the model uses, particularly in the Code tab; or where workarounds were needed for missing features)

## RELATED MODELS

(models in the NetLogo Models Library and elsewhere which are of related interest)

## CREDITS AND REFERENCES

(a reference to the model's URL on the web if it has one, as well as any other necessary credits, citations, and links)
@#$#@#$#@
default
true
0
Polygon -7500403 true true 150 5 40 250 150 205 260 250

airplane
true
0
Polygon -7500403 true true 150 0 135 15 120 60 120 105 15 165 15 195 120 180 135 240 105 270 120 285 150 270 180 285 210 270 165 240 180 180 285 195 285 165 180 105 180 60 165 15

arrow
true
0
Polygon -7500403 true true 150 0 0 150 105 150 105 293 195 293 195 150 300 150

box
false
0
Polygon -7500403 true true 150 285 285 225 285 75 150 135
Polygon -7500403 true true 150 135 15 75 150 15 285 75
Polygon -7500403 true true 15 75 15 225 150 285 150 135
Line -16777216 false 150 285 150 135
Line -16777216 false 150 135 15 75
Line -16777216 false 150 135 285 75

bug
true
0
Circle -7500403 true true 96 182 108
Circle -7500403 true true 110 127 80
Circle -7500403 true true 110 75 80
Line -7500403 true 150 100 80 30
Line -7500403 true 150 100 220 30

butterfly
true
0
Polygon -7500403 true true 150 165 209 199 225 225 225 255 195 270 165 255 150 240
Polygon -7500403 true true 150 165 89 198 75 225 75 255 105 270 135 255 150 240
Polygon -7500403 true true 139 148 100 105 55 90 25 90 10 105 10 135 25 180 40 195 85 194 139 163
Polygon -7500403 true true 162 150 200 105 245 90 275 90 290 105 290 135 275 180 260 195 215 195 162 165
Polygon -16777216 true false 150 255 135 225 120 150 135 120 150 105 165 120 180 150 165 225
Circle -16777216 true false 135 90 30
Line -16777216 false 150 105 195 60
Line -16777216 false 150 105 105 60

car
false
0
Polygon -7500403 true true 300 180 279 164 261 144 240 135 226 132 213 106 203 84 185 63 159 50 135 50 75 60 0 150 0 165 0 225 300 225 300 180
Circle -16777216 true false 180 180 90
Circle -16777216 true false 30 180 90
Polygon -16777216 true false 162 80 132 78 134 135 209 135 194 105 189 96 180 89
Circle -7500403 true true 47 195 58
Circle -7500403 true true 195 195 58

circle
false
0
Circle -7500403 true true 0 0 300

circle 2
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240

cow
false
0
Polygon -7500403 true true 200 193 197 249 179 249 177 196 166 187 140 189 93 191 78 179 72 211 49 209 48 181 37 149 25 120 25 89 45 72 103 84 179 75 198 76 252 64 272 81 293 103 285 121 255 121 242 118 224 167
Polygon -7500403 true true 73 210 86 251 62 249 48 208
Polygon -7500403 true true 25 114 16 195 9 204 23 213 25 200 39 123

cylinder
false
0
Circle -7500403 true true 0 0 300

dot
false
0
Circle -7500403 true true 90 90 120

face happy
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 255 90 239 62 213 47 191 67 179 90 203 109 218 150 225 192 218 210 203 227 181 251 194 236 217 212 240

face neutral
false
0
Circle -7500403 true true 8 7 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Rectangle -16777216 true false 60 195 240 225

face sad
false
0
Circle -7500403 true true 8 8 285
Circle -16777216 true false 60 75 60
Circle -16777216 true false 180 75 60
Polygon -16777216 true false 150 168 90 184 62 210 47 232 67 244 90 220 109 205 150 198 192 205 210 220 227 242 251 229 236 206 212 183

fish
false
0
Polygon -1 true false 44 131 21 87 15 86 0 120 15 150 0 180 13 214 20 212 45 166
Polygon -1 true false 135 195 119 235 95 218 76 210 46 204 60 165
Polygon -1 true false 75 45 83 77 71 103 86 114 166 78 135 60
Polygon -7500403 true true 30 136 151 77 226 81 280 119 292 146 292 160 287 170 270 195 195 210 151 212 30 166
Circle -16777216 true false 215 106 30

flag
false
0
Rectangle -7500403 true true 60 15 75 300
Polygon -7500403 true true 90 150 270 90 90 30
Line -7500403 true 75 135 90 135
Line -7500403 true 75 45 90 45

flower
false
0
Polygon -10899396 true false 135 120 165 165 180 210 180 240 150 300 165 300 195 240 195 195 165 135
Circle -7500403 true true 85 132 38
Circle -7500403 true true 130 147 38
Circle -7500403 true true 192 85 38
Circle -7500403 true true 85 40 38
Circle -7500403 true true 177 40 38
Circle -7500403 true true 177 132 38
Circle -7500403 true true 70 85 38
Circle -7500403 true true 130 25 38
Circle -7500403 true true 96 51 108
Circle -16777216 true false 113 68 74
Polygon -10899396 true false 189 233 219 188 249 173 279 188 234 218
Polygon -10899396 true false 180 255 150 210 105 210 75 240 135 240

house
false
0
Rectangle -7500403 true true 45 120 255 285
Rectangle -16777216 true false 120 210 180 285
Polygon -7500403 true true 15 120 150 15 285 120
Line -16777216 false 30 120 270 120

leaf
false
0
Polygon -7500403 true true 150 210 135 195 120 210 60 210 30 195 60 180 60 165 15 135 30 120 15 105 40 104 45 90 60 90 90 105 105 120 120 120 105 60 120 60 135 30 150 15 165 30 180 60 195 60 180 120 195 120 210 105 240 90 255 90 263 104 285 105 270 120 285 135 240 165 240 180 270 195 240 210 180 210 165 195
Polygon -7500403 true true 135 195 135 240 120 255 105 255 105 285 135 285 165 240 165 195

line
true
0
Line -7500403 true 150 0 150 300

line half
true
0
Line -7500403 true 150 0 150 150

pentagon
false
0
Polygon -7500403 true true 150 15 15 120 60 285 240 285 285 120

person
false
0
Circle -7500403 true true 110 5 80
Polygon -7500403 true true 105 90 120 195 90 285 105 300 135 300 150 225 165 300 195 300 210 285 180 195 195 90
Rectangle -7500403 true true 127 79 172 94
Polygon -7500403 true true 195 90 240 150 225 180 165 105
Polygon -7500403 true true 105 90 60 150 75 180 135 105

plant
false
0
Rectangle -7500403 true true 135 90 165 300
Polygon -7500403 true true 135 255 90 210 45 195 75 255 135 285
Polygon -7500403 true true 165 255 210 210 255 195 225 255 165 285
Polygon -7500403 true true 135 180 90 135 45 120 75 180 135 210
Polygon -7500403 true true 165 180 165 210 225 180 255 120 210 135
Polygon -7500403 true true 135 105 90 60 45 45 75 105 135 135
Polygon -7500403 true true 165 105 165 135 225 105 255 45 210 60
Polygon -7500403 true true 135 90 120 45 150 15 180 45 165 90

sheep
false
15
Circle -1 true true 203 65 88
Circle -1 true true 70 65 162
Circle -1 true true 150 105 120
Polygon -7500403 true false 218 120 240 165 255 165 278 120
Circle -7500403 true false 214 72 67
Rectangle -1 true true 164 223 179 298
Polygon -1 true true 45 285 30 285 30 240 15 195 45 210
Circle -1 true true 3 83 150
Rectangle -1 true true 65 221 80 296
Polygon -1 true true 195 285 210 285 210 240 240 210 195 210
Polygon -7500403 true false 276 85 285 105 302 99 294 83
Polygon -7500403 true false 219 85 210 105 193 99 201 83

square
false
0
Rectangle -7500403 true true 30 30 270 270

square 2
false
0
Rectangle -7500403 true true 30 30 270 270
Rectangle -16777216 true false 60 60 240 240

star
false
0
Polygon -7500403 true true 151 1 185 108 298 108 207 175 242 282 151 216 59 282 94 175 3 108 116 108

target
false
0
Circle -7500403 true true 0 0 300
Circle -16777216 true false 30 30 240
Circle -7500403 true true 60 60 180
Circle -16777216 true false 90 90 120
Circle -7500403 true true 120 120 60

tree
false
0
Circle -7500403 true true 118 3 94
Rectangle -6459832 true false 120 195 180 300
Circle -7500403 true true 65 21 108
Circle -7500403 true true 116 41 127
Circle -7500403 true true 45 90 120
Circle -7500403 true true 104 74 152

triangle
false
0
Polygon -7500403 true true 150 30 15 255 285 255

triangle 2
false
0
Polygon -7500403 true true 150 30 15 255 285 255
Polygon -16777216 true false 151 99 225 223 75 224

truck
false
0
Rectangle -7500403 true true 4 45 195 187
Polygon -7500403 true true 296 193 296 150 259 134 244 104 208 104 207 194
Rectangle -1 true false 195 60 195 105
Polygon -16777216 true false 238 112 252 141 219 141 218 112
Circle -16777216 true false 234 174 42
Rectangle -7500403 true true 181 185 214 194
Circle -16777216 true false 144 174 42
Circle -16777216 true false 24 174 42
Circle -7500403 false true 24 174 42
Circle -7500403 false true 144 174 42
Circle -7500403 false true 234 174 42

turtle
true
0
Polygon -10899396 true false 215 204 240 233 246 254 228 266 215 252 193 210
Polygon -10899396 true false 195 90 225 75 245 75 260 89 269 108 261 124 240 105 225 105 210 105
Polygon -10899396 true false 105 90 75 75 55 75 40 89 31 108 39 124 60 105 75 105 90 105
Polygon -10899396 true false 132 85 134 64 107 51 108 17 150 2 192 18 192 52 169 65 172 87
Polygon -10899396 true false 85 204 60 233 54 254 72 266 85 252 107 210
Polygon -7500403 true true 119 75 179 75 209 101 224 135 220 225 175 261 128 261 81 224 74 135 88 99

wheel
false
0
Circle -7500403 true true 3 3 294
Circle -16777216 true false 30 30 240
Line -7500403 true 150 285 150 15
Line -7500403 true 15 150 285 150
Circle -7500403 true true 120 120 60
Line -7500403 true 216 40 79 269
Line -7500403 true 40 84 269 221
Line -7500403 true 40 216 269 79
Line -7500403 true 84 40 221 269

wolf
false
0
Polygon -16777216 true false 253 133 245 131 245 133
Polygon -7500403 true true 2 194 13 197 30 191 38 193 38 205 20 226 20 257 27 265 38 266 40 260 31 253 31 230 60 206 68 198 75 209 66 228 65 243 82 261 84 268 100 267 103 261 77 239 79 231 100 207 98 196 119 201 143 202 160 195 166 210 172 213 173 238 167 251 160 248 154 265 169 264 178 247 186 240 198 260 200 271 217 271 219 262 207 258 195 230 192 198 210 184 227 164 242 144 259 145 284 151 277 141 293 140 299 134 297 127 273 119 270 105
Polygon -7500403 true true -1 195 14 180 36 166 40 153 53 140 82 131 134 133 159 126 188 115 227 108 236 102 238 98 268 86 269 92 281 87 269 103 269 113

x
false
0
Polygon -7500403 true true 270 75 225 30 30 225 75 270
Polygon -7500403 true true 30 75 75 30 270 225 225 270

@#$#@#$#@
NetLogo 6.0-M5
@#$#@#$#@
@#$#@#$#@
@#$#@#$#@
<experiments>
  <experiment name="Sexual Assault" repetitions="10" runMetricsEveryStep="true">
    <setup>setup</setup>
    <go>go</go>
    <timeLimit steps="5000"/>
    <metric>count turtles with [color = red]</metric>
    <enumeratedValueSet variable="hostility">
      <value value="1"/>
      <value value="5"/>
      <value value="10"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="women">
      <value value="50"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="men">
      <value value="100"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="empathy">
      <value value="1"/>
      <value value="5"/>
      <value value="10"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="education">
      <value value="1"/>
      <value value="5"/>
      <value value="10"/>
    </enumeratedValueSet>
    <enumeratedValueSet variable="alcohol">
      <value value="1"/>
      <value value="5"/>
      <value value="10"/>
    </enumeratedValueSet>
  </experiment>
</experiments>
@#$#@#$#@
@#$#@#$#@
default
0.0
-0.2 0 0.0 1.0
0.0 1 1.0 0.0
0.2 0 0.0 1.0
link direction
true
0
Line -7500403 true 150 150 90 180
Line -7500403 true 150 150 210 180

@#$#@#$#@
0
@#$#@#$#@
