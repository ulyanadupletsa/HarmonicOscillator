#ifndef ACTION_H
#define ACTION_H

#ifndef OA_C
extern float action(void);
#endif

#ifndef DS_C
extern float deltas(float y, int j);
#endif

#ifndef EVOLUTION_C
extern void evolution(float S[]);
#endif

#ifndef AUTOCORR_C
extern void autocorr (void);
#endif

#ifndef CORRELATORBINN_C
extern void correlatorbinn (void);
#endif

#ifndef CORRELATORMEAN_C
extern void correlatormean (void);
#endif

#ifndef CORRELATORSIGMA_C
extern void correlatorsigma (void);
#endif


#endif 
