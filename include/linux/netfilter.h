# i f n d e f   _ _ L I N U X _ N E T F I L T E R _ H 
 # d e f i n e   _ _ L I N U X _ N E T F I L T E R _ H 
 
 # i f d e f   _ _ K E R N E L _ _ 
 # i n c l u d e   < l i n u x / i n i t . h > 
 # i n c l u d e   < l i n u x / s k b u f f . h > 
 # i n c l u d e   < l i n u x / n e t . h > 
 # i n c l u d e   < l i n u x / i f . h > 
 # i n c l u d e   < l i n u x / i n . h > 
 # i n c l u d e   < l i n u x / i n 6 . h > 
 # i n c l u d e   < l i n u x / w a i t . h > 
 # i n c l u d e   < l i n u x / l i s t . h > 
 # e n d i f 
 # i n c l u d e   < l i n u x / t y p e s . h > 
 # i n c l u d e   < l i n u x / c o m p i l e r . h > 
 
 / *   R e s p o n s e s   f r o m   h o o k   f u n c t i o n s .   * / 
 # d e f i n e   N F _ D R O P   0 
 # d e f i n e   N F _ A C C E P T   1 
 # d e f i n e   N F _ S T O L E N   2 
 # d e f i n e   N F _ Q U E U E   3 
 # d e f i n e   N F _ R E P E A T   4 
 # d e f i n e   N F _ S T O P   5 
 # d e f i n e   N F _ M A X _ V E R D I C T   N F _ S T O P 
 
 / *   w e   o v e r l o a d   t h e   h i g h e r   b i t s   f o r   e n c o d i n g   a u x i l i a r y   d a t a   s u c h   a s   t h e   q u e u e 
   *   n u m b e r .   N o t   n i c e ,   b u t   b e t t e r   t h a n   a d d i t i o n a l   f u n c t i o n   a r g u m e n t s .   * / 
 # d e f i n e   N F _ V E R D I C T _ M A S K   0 x 0 0 0 0 f f f f 
 # d e f i n e   N F _ V E R D I C T _ B I T S   1 6 
 
 # d e f i n e   N F _ V E R D I C T _ Q M A S K   0 x f f f f 0 0 0 0 
 # d e f i n e   N F _ V E R D I C T _ Q B I T S   1 6 
 
 # d e f i n e   N F _ Q U E U E _ N R ( x )   ( ( ( ( x )   < <   N F _ V E R D I C T _ B I T S )   &   N F _ V E R D I C T _ Q M A S K )   |   N F _ Q U E U E ) 
 
 / *   o n l y   f o r   u s e r s p a c e   c o m p a t i b i l i t y   * / 
 # i f n d e f   _ _ K E R N E L _ _ 
 / *   G e n e r i c   c a c h e   r e s p o n s e s   f r o m   h o o k   f u n c t i o n s . 
       < =   0 x 2 0 0 0   i s   u s e d   f o r   p r o t o c o l - f l a g s .   * / 
 # d e f i n e   N F C _ U N K N O W N   0 x 4 0 0 0 
 # d e f i n e   N F C _ A L T E R E D   0 x 8 0 0 0 
 # e n d i f 
 
 e n u m   n f _ i n e t _ h o o k s   { 
 	 N F _ I N E T _ P R E _ R O U T I N G , 
 	 N F _ I N E T _ L O C A L _ I N , 
 	 N F _ I N E T _ F O R W A R D , 
 	 N F _ I N E T _ L O C A L _ O U T , 
 	 N F _ I N E T _ P O S T _ R O U T I N G , 
 	 N F _ I N E T _ N U M H O O K S 
 } ; 
 
 e n u m   { 
 	 N F P R O T O _ U N S P E C   =     0 , 
 	 N F P R O T O _ I P V 4       =     2 , 
 	 N F P R O T O _ A R P         =     3 , 
 	 N F P R O T O _ B R I D G E   =     7 , 
 	 N F P R O T O _ I P V 6       =   1 0 , 
 	 N F P R O T O _ D E C N E T   =   1 2 , 
 	 N F P R O T O _ N U M P R O T O , 
 } ; 
 
 u n i o n   n f _ i n e t _ a d d r   { 
 	 / * S_	NB\OS��N/fi p v 4 0i p v 6 �e�O(u�bXTX[�P* / 
 	 _ _ u 3 2 	 	 a l l [ 4 ] ; 
 	 / * S_	NB\OS��/fi p v 4 �e�O(u�bXTX[�Pi p v 4 0W@W* / 
 	 _ _ b e 3 2 	 	 i p ; 
 	 / * S_	NB\OS��/fi p v 6 bXT�e�O(u�bXTX[�Pi p v 6 0W@W* / 
 	 _ _ b e 3 2 	 	 i p 6 [ 4 ] ; 
 	 s t r u c t   i n _ a d d r 	 i n ; 
 	 s t r u c t   i n 6 _ a d d r 	 i n 6 ; 
 } ; 
 
 # i f d e f   _ _ K E R N E L _ _ 
 # i f d e f   C O N F I G _ N E T F I L T E R 
 
 s t a t i c   i n l i n e   i n t   n f _ i n e t _ a d d r _ c m p ( c o n s t   u n i o n   n f _ i n e t _ a d d r   * a 1 , 
 	 	 	 	       c o n s t   u n i o n   n f _ i n e t _ a d d r   * a 2 ) 
 { 
 	 r e t u r n   a 1 - > a l l [ 0 ]   = =   a 2 - > a l l [ 0 ]   & & 
 	               a 1 - > a l l [ 1 ]   = =   a 2 - > a l l [ 1 ]   & & 
 	               a 1 - > a l l [ 2 ]   = =   a 2 - > a l l [ 2 ]   & & 
 	               a 1 - > a l l [ 3 ]   = =   a 2 - > a l l [ 3 ] ; 
 } 
 
 e x t e r n   v o i d   n e t f i l t e r _ i n i t ( v o i d ) ; 
 
 / *   L a r g e s t   h o o k   n u m b e r   +   1   * / 
 # d e f i n e   N F _ M A X _ H O O K S   8 
 
 s t r u c t   s k _ b u f f ; 
 
 t y p e d e f   u n s i g n e d   i n t   n f _ h o o k f n ( u n s i g n e d   i n t   h o o k n u m , 
 	 	 	               s t r u c t   s k _ b u f f   * s k b , 
 	 	 	               c o n s t   s t r u c t   n e t _ d e v i c e   * i n , 
 	 	 	               c o n s t   s t r u c t   n e t _ d e v i c e   * o u t , 
 	 	 	               i n t   ( * o k f n ) ( s t r u c t   s k _ b u f f   * ) ) ; 
 
 s t r u c t   n f _ h o o k _ o p s 
 { 
 	 s t r u c t   l i s t _ h e a d   l i s t ; 
 
 	 / *   U s e r   f i l l s   i n   f r o m   h e r e   d o w n .   * / 
 	 / / � � � � � � � � . . . 
 	 n f _ h o o k f n   * h o o k ; 
 	 s t r u c t   m o d u l e   * o w n e r ; 
 	 / / � � � � � � � � � � � � � � � � � � � � . . . e g :   P F _ I N E T 
 	 u _ i n t 8 _ t   p f ; 
 	 / / � � � � � � � � � � � � � � � � . . . 
 	 u n s i g n e d   i n t   h o o k n u m ; 
 	 / *   H o o k s   a r e   o r d e r e d   i n   a s c e n d i n g   p r i o r i t y .   * / 
 	 / / � � � � � � � � � � � � � � � � . . . . 
 	 i n t   p r i o r i t y ; 
 } ; 
 
 s t r u c t   n f _ s o c k o p t _ o p s 
 { 
 	 s t r u c t   l i s t _ h e a d   l i s t ; 
 
 	 u _ i n t 8 _ t   p f ; 
 
 	 / *   N o n - i n c l u s i v e   r a n g e s :   u s e   0 / 0 / N U L L   t o   n e v e r   g e t   c a l l e d .   * / 
 	 i n t   s e t _ o p t m i n ; 
 	 i n t   s e t _ o p t m a x ; 
 	 i n t   ( * s e t ) ( s t r u c t   s o c k   * s k ,   i n t   o p t v a l ,   v o i d   _ _ u s e r   * u s e r ,   u n s i g n e d   i n t   l e n ) ; 
 	 i n t   ( * c o m p a t _ s e t ) ( s t r u c t   s o c k   * s k ,   i n t   o p t v a l , 
 	 	 	 v o i d   _ _ u s e r   * u s e r ,   u n s i g n e d   i n t   l e n ) ; 
 
 	 i n t   g e t _ o p t m i n ; 
 	 i n t   g e t _ o p t m a x ; 
 	 i n t   ( * g e t ) ( s t r u c t   s o c k   * s k ,   i n t   o p t v a l ,   v o i d   _ _ u s e r   * u s e r ,   i n t   * l e n ) ; 
 	 i n t   ( * c o m p a t _ g e t ) ( s t r u c t   s o c k   * s k ,   i n t   o p t v a l , 
 	 	 	 v o i d   _ _ u s e r   * u s e r ,   i n t   * l e n ) ; 
 
 	 / *   U s e   t h e   m o d u l e   s t r u c t   t o   l o c k   s e t / g e t   c o d e   i n   p l a c e   * / 
 	 s t r u c t   m o d u l e   * o w n e r ; 
 } ; 
 
 / *   F u n c t i o n   t o   r e g i s t e r / u n r e g i s t e r   h o o k   p o i n t s .   * / 
 i n t   n f _ r e g i s t e r _ h o o k ( s t r u c t   n f _ h o o k _ o p s   * r e g ) ; 
 v o i d   n f _ u n r e g i s t e r _ h o o k ( s t r u c t   n f _ h o o k _ o p s   * r e g ) ; 
 i n t   n f _ r e g i s t e r _ h o o k s ( s t r u c t   n f _ h o o k _ o p s   * r e g ,   u n s i g n e d   i n t   n ) ; 
 v o i d   n f _ u n r e g i s t e r _ h o o k s ( s t r u c t   n f _ h o o k _ o p s   * r e g ,   u n s i g n e d   i n t   n ) ; 
 
 / *   F u n c t i o n s   t o   r e g i s t e r   g e t / s e t s o c k o p t   r a n g e s   ( n o n - i n c l u s i v e ) .     Y o u 
       n e e d   t o   c h e c k   p e r m i s s i o n s   y o u r s e l f !   * / 
 i n t   n f _ r e g i s t e r _ s o c k o p t ( s t r u c t   n f _ s o c k o p t _ o p s   * r e g ) ; 
 v o i d   n f _ u n r e g i s t e r _ s o c k o p t ( s t r u c t   n f _ s o c k o p t _ o p s   * r e g ) ; 
 
 # i f d e f   C O N F I G _ S Y S C T L 
 / *   S y s c t l   r e g i s t r a t i o n   * / 
 e x t e r n   s t r u c t   c t l _ p a t h   n f _ n e t _ n e t f i l t e r _ s y s c t l _ p a t h [ ] ; 
 e x t e r n   s t r u c t   c t l _ p a t h   n f _ n e t _ i p v 4 _ n e t f i l t e r _ s y s c t l _ p a t h [ ] ; 
 # e n d i f   / *   C O N F I G _ S Y S C T L   * / 
 
 e x t e r n   s t r u c t   l i s t _ h e a d   n f _ h o o k s [ N F P R O T O _ N U M P R O T O ] [ N F _ M A X _ H O O K S ] ; 
 
 i n t   n f _ h o o k _ s l o w ( u _ i n t 8 _ t   p f ,   u n s i g n e d   i n t   h o o k ,   s t r u c t   s k _ b u f f   * s k b , 
 	 	   s t r u c t   n e t _ d e v i c e   * i n d e v ,   s t r u c t   n e t _ d e v i c e   * o u t d e v , 
 	 	   i n t   ( * o k f n ) ( s t r u c t   s k _ b u f f   * ) ,   i n t   t h r e s h ) ; 
 
 / * * 
   * 	 n f _ h o o k _ t h r e s h   -   c a l l   a   n e t f i l t e r   h o o k 
   * 	 
   * 	 R e t u r n s   1   i f   t h e   h o o k   h a s   a l l o w e d   t h e   p a c k e t   t o   p a s s .     T h e   f u n c t i o n 
   * 	 o k f n   m u s t   b e   i n v o k e d   b y   t h e   c a l l e r   i n   t h i s   c a s e .     A n y   o t h e r   r e t u r n 
   * 	 v a l u e   i n d i c a t e s   t h e   p a c k e t   h a s   b e e n   c o n s u m e d   b y   t h e   h o o k . 
   * / 
 s t a t i c   i n l i n e   i n t   n f _ h o o k _ t h r e s h ( u _ i n t 8 _ t   p f ,   u n s i g n e d   i n t   h o o k , 
 	 	 	 	   s t r u c t   s k _ b u f f   * s k b , 
 	 	 	 	   s t r u c t   n e t _ d e v i c e   * i n d e v , 
 	 	 	 	   s t r u c t   n e t _ d e v i c e   * o u t d e v , 
 	 	 	 	   i n t   ( * o k f n ) ( s t r u c t   s k _ b u f f   * ) ,   i n t   t h r e s h , 
 	 	 	 	   i n t   c o n d ) 
 { 
 	 i f   ( ! c o n d ) 
 	 	 r e t u r n   1 ; 
 # i f n d e f   C O N F I G _ N E T F I L T E R _ D E B U G 
 	 i f   ( l i s t _ e m p t y ( & n f _ h o o k s [ p f ] [ h o o k ] ) ) 
 	 	 r e t u r n   1 ; 
 # e n d i f 
 	 r e t u r n   n f _ h o o k _ s l o w ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n ,   t h r e s h ) ; 
 } 
 
 s t a t i c   i n l i n e   i n t   n f _ h o o k ( u _ i n t 8 _ t   p f ,   u n s i g n e d   i n t   h o o k ,   s t r u c t   s k _ b u f f   * s k b , 
 	 	 	     s t r u c t   n e t _ d e v i c e   * i n d e v ,   s t r u c t   n e t _ d e v i c e   * o u t d e v , 
 	 	 	     i n t   ( * o k f n ) ( s t r u c t   s k _ b u f f   * ) ) 
 { 
 	 r e t u r n   n f _ h o o k _ t h r e s h ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n ,   I N T _ M I N ,   1 ) ; 
 } 
                                       
 / *   A c t i v a t e   h o o k ;   e i t h e r   o k f n   o r   k f r e e _ s k b   c a l l e d ,   u n l e s s   a   h o o k 
       r e t u r n s   N F _ S T O L E N   ( i n   w h i c h   c a s e ,   i t ' s   u p   t o   t h e   h o o k   t o   d e a l   w i t h 
       t h e   c o n s e q u e n c e s ) . 
 
       R e t u r n s   - E R R N O   i f   p a c k e t   d r o p p e d .     Z e r o   m e a n s   q u e u e d ,   s t o l e n   o r 
       a c c e p t e d . 
 * / 
 
 / *   R R : 
       >   I   d o n ' t   w a n t   n f _ h o o k   t o   r e t u r n   a n y t h i n g   b e c a u s e   p e o p l e   m i g h t   f o r g e t 
       >   a b o u t   a s y n c   a n d   t r u s t   t h e   r e t u r n   v a l u e   t o   m e a n   " p a c k e t   w a s   o k " . 
 
       A K : 
       J u s t   d o c u m e n t   i t   c l e a r l y ,   t h e n   y o u   c a n   e x p e c t   s o m e   s e n s e   f r o m   k e r n e l 
       c o d e r s   : ) 
 * / 
 
 / *   T h i s   i s   g r o s s ,   b u t   i n l i n e   d o e s n ' t   c u t   i t   f o r   a v o i d i n g   t h e   f u n c t i o n 
       c a l l   i n   f a s t   p a t h :   g c c   d o e s n ' t   i n l i n e   ( n e e d s   v a l u e   t r a c k i n g ? ) .   - - R R   * / 
 
 / *   H X :   I t ' s   s l i g h t l y   l e s s   g r o s s   n o w .   * / 
 
 # d e f i n e   N F _ H O O K _ T H R E S H ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n ,   t h r e s h ) 	               \ 
 ( { i n t   _ _ r e t ; 	 	 	 	 	 	 	 	               \ 
 i f   ( ( _ _ r e t = n f _ h o o k _ t h r e s h ( p f ,   h o o k ,   ( s k b ) ,   i n d e v ,   o u t d e v ,   o k f n ,   t h r e s h ,   1 ) )   = =   1 ) \ 
 	 _ _ r e t   =   ( o k f n ) ( s k b ) ; 	 	 	 	 	 	               \ 
 _ _ r e t ; } ) 
 
 # d e f i n e   N F _ H O O K _ C O N D ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n ,   c o n d ) 	 	               \ 
 ( { i n t   _ _ r e t ; 	 	 	 	 	 	 	 	               \ 
 i f   ( ( _ _ r e t = n f _ h o o k _ t h r e s h ( p f ,   h o o k ,   ( s k b ) ,   i n d e v ,   o u t d e v ,   o k f n ,   I N T _ M I N ,   c o n d ) )   = =   1 ) \ 
 	 _ _ r e t   =   ( o k f n ) ( s k b ) ; 	 	 	 	 	 	               \ 
 _ _ r e t ; } ) 
 / / p f � � � � � � � � � � � � . . . � � � � � � i p v 4   i p v 6 � � . . � � � � � � 5 3 � � � � � � � � � � � � � � � � � � . . . 
 # d e f i n e   N F _ H O O K ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n )   \ 
 	 N F _ H O O K _ T H R E S H ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n ,   I N T _ M I N ) 
 
 / *   C a l l   s e t s o c k o p t ( )   * / 
 i n t   n f _ s e t s o c k o p t ( s t r u c t   s o c k   * s k ,   u _ i n t 8 _ t   p f ,   i n t   o p t v a l ,   c h a r   _ _ u s e r   * o p t , 
 	 	     i n t   l e n ) ; 
 i n t   n f _ g e t s o c k o p t ( s t r u c t   s o c k   * s k ,   u _ i n t 8 _ t   p f ,   i n t   o p t v a l ,   c h a r   _ _ u s e r   * o p t , 
 	 	     i n t   * l e n ) ; 
 
 i n t   c o m p a t _ n f _ s e t s o c k o p t ( s t r u c t   s o c k   * s k ,   u _ i n t 8 _ t   p f ,   i n t   o p t v a l , 
 	 	 c h a r   _ _ u s e r   * o p t ,   i n t   l e n ) ; 
 i n t   c o m p a t _ n f _ g e t s o c k o p t ( s t r u c t   s o c k   * s k ,   u _ i n t 8 _ t   p f ,   i n t   o p t v a l , 
 	 	 c h a r   _ _ u s e r   * o p t ,   i n t   * l e n ) ; 
 
 / *   C a l l   t h i s   b e f o r e   m o d i f y i n g   a n   e x i s t i n g   p a c k e t :   e n s u r e s   i t   i s 
       m o d i f i a b l e   a n d   l i n e a r   t o   t h e   p o i n t   y o u   c a r e   a b o u t   ( w r i t a b l e _ l e n ) . 
       R e t u r n s   t r u e   o r   f a l s e .   * / 
 e x t e r n   i n t   s k b _ m a k e _ w r i t a b l e ( s t r u c t   s k _ b u f f   * s k b ,   u n s i g n e d   i n t   w r i t a b l e _ l e n ) ; 
 
 s t r u c t   f l o w i ; 
 s t r u c t   n f _ q u e u e _ e n t r y ; 
 
 s t r u c t   n f _ a f i n f o   { 
 	 u n s i g n e d   s h o r t 	 f a m i l y ; 
 	 _ _ s u m 1 6 	 	 ( * c h e c k s u m ) ( s t r u c t   s k _ b u f f   * s k b ,   u n s i g n e d   i n t   h o o k , 
 	 	 	 	         u n s i g n e d   i n t   d a t a o f f ,   u _ i n t 8 _ t   p r o t o c o l ) ; 
 	 _ _ s u m 1 6 	 	 ( * c h e c k s u m _ p a r t i a l ) ( s t r u c t   s k _ b u f f   * s k b , 
 	 	 	 	 	         u n s i g n e d   i n t   h o o k , 
 	 	 	 	 	         u n s i g n e d   i n t   d a t a o f f , 
 	 	 	 	 	         u n s i g n e d   i n t   l e n , 
 	 	 	 	 	         u _ i n t 8 _ t   p r o t o c o l ) ; 
 	 i n t 	 	 ( * r o u t e ) ( s t r u c t   d s t _ e n t r y   * * d s t ,   s t r u c t   f l o w i   * f l ) ; 
 	 v o i d 	 	 ( * s a v e r o u t e ) ( c o n s t   s t r u c t   s k _ b u f f   * s k b , 
 	 	 	 	           s t r u c t   n f _ q u e u e _ e n t r y   * e n t r y ) ; 
 	 i n t 	 	 ( * r e r o u t e ) ( s t r u c t   s k _ b u f f   * s k b , 
 	 	 	 	       c o n s t   s t r u c t   n f _ q u e u e _ e n t r y   * e n t r y ) ; 
 	 i n t 	 	 r o u t e _ k e y _ s i z e ; 
 } ; 
 
 e x t e r n   c o n s t   s t r u c t   n f _ a f i n f o   * n f _ a f i n f o [ N F P R O T O _ N U M P R O T O ] ; 
 s t a t i c   i n l i n e   c o n s t   s t r u c t   n f _ a f i n f o   * n f _ g e t _ a f i n f o ( u n s i g n e d   s h o r t   f a m i l y ) 
 { 
 	 r e t u r n   r c u _ d e r e f e r e n c e ( n f _ a f i n f o [ f a m i l y ] ) ; 
 } 
 
 s t a t i c   i n l i n e   _ _ s u m 1 6 
 n f _ c h e c k s u m ( s t r u c t   s k _ b u f f   * s k b ,   u n s i g n e d   i n t   h o o k ,   u n s i g n e d   i n t   d a t a o f f , 
 	         u _ i n t 8 _ t   p r o t o c o l ,   u n s i g n e d   s h o r t   f a m i l y ) 
 { 
 	 c o n s t   s t r u c t   n f _ a f i n f o   * a f i n f o ; 
 	 _ _ s u m 1 6   c s u m   =   0 ; 
 
 	 r c u _ r e a d _ l o c k ( ) ; 
 	 a f i n f o   =   n f _ g e t _ a f i n f o ( f a m i l y ) ; 
 	 i f   ( a f i n f o ) 
 	 	 c s u m   =   a f i n f o - > c h e c k s u m ( s k b ,   h o o k ,   d a t a o f f ,   p r o t o c o l ) ; 
 	 r c u _ r e a d _ u n l o c k ( ) ; 
 	 r e t u r n   c s u m ; 
 } 
 
 s t a t i c   i n l i n e   _ _ s u m 1 6 
 n f _ c h e c k s u m _ p a r t i a l ( s t r u c t   s k _ b u f f   * s k b ,   u n s i g n e d   i n t   h o o k , 
 	 	         u n s i g n e d   i n t   d a t a o f f ,   u n s i g n e d   i n t   l e n , 
 	 	         u _ i n t 8 _ t   p r o t o c o l ,   u n s i g n e d   s h o r t   f a m i l y ) 
 { 
 	 c o n s t   s t r u c t   n f _ a f i n f o   * a f i n f o ; 
 	 _ _ s u m 1 6   c s u m   =   0 ; 
 
 	 r c u _ r e a d _ l o c k ( ) ; 
 	 a f i n f o   =   n f _ g e t _ a f i n f o ( f a m i l y ) ; 
 	 i f   ( a f i n f o ) 
 	 	 c s u m   =   a f i n f o - > c h e c k s u m _ p a r t i a l ( s k b ,   h o o k ,   d a t a o f f ,   l e n , 
 	 	 	 	 	 	 p r o t o c o l ) ; 
 	 r c u _ r e a d _ u n l o c k ( ) ; 
 	 r e t u r n   c s u m ; 
 } 
 
 e x t e r n   i n t   n f _ r e g i s t e r _ a f i n f o ( c o n s t   s t r u c t   n f _ a f i n f o   * a f i n f o ) ; 
 e x t e r n   v o i d   n f _ u n r e g i s t e r _ a f i n f o ( c o n s t   s t r u c t   n f _ a f i n f o   * a f i n f o ) ; 
 
 # i n c l u d e   < n e t / f l o w . h > 
 e x t e r n   v o i d   ( * i p _ n a t _ d e c o d e _ s e s s i o n ) ( s t r u c t   s k _ b u f f   * ,   s t r u c t   f l o w i   * ) ; 
 
 s t a t i c   i n l i n e   v o i d 
 n f _ n a t _ d e c o d e _ s e s s i o n ( s t r u c t   s k _ b u f f   * s k b ,   s t r u c t   f l o w i   * f l ,   u _ i n t 8 _ t   f a m i l y ) 
 { 
 # i f d e f   C O N F I G _ N F _ N A T _ N E E D E D 
 	 v o i d   ( * d e c o d e f n ) ( s t r u c t   s k _ b u f f   * ,   s t r u c t   f l o w i   * ) ; 
 
 	 i f   ( f a m i l y   = =   A F _ I N E T )   { 
 	 	 r c u _ r e a d _ l o c k ( ) ; 
 	 	 d e c o d e f n   =   r c u _ d e r e f e r e n c e ( i p _ n a t _ d e c o d e _ s e s s i o n ) ; 
 	 	 i f   ( d e c o d e f n ) 
 	 	 	 d e c o d e f n ( s k b ,   f l ) ; 
 	 	 r c u _ r e a d _ u n l o c k ( ) ; 
 	 } 
 # e n d i f 
 } 
 
 # i f d e f   C O N F I G _ P R O C _ F S 
 # i n c l u d e   < l i n u x / p r o c _ f s . h > 
 e x t e r n   s t r u c t   p r o c _ d i r _ e n t r y   * p r o c _ n e t _ n e t f i l t e r ; 
 # e n d i f 
 
 # e l s e   / *   ! C O N F I G _ N E T F I L T E R   * / 
 # d e f i n e   N F _ H O O K ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n )   ( o k f n ) ( s k b ) 
 # d e f i n e   N F _ H O O K _ C O N D ( p f ,   h o o k ,   s k b ,   i n d e v ,   o u t d e v ,   o k f n ,   c o n d )   ( o k f n ) ( s k b ) 
 s t a t i c   i n l i n e   i n t   n f _ h o o k _ t h r e s h ( u _ i n t 8 _ t   p f ,   u n s i g n e d   i n t   h o o k , 
 	 	 	 	   s t r u c t   s k _ b u f f   * s k b , 
 	 	 	 	   s t r u c t   n e t _ d e v i c e   * i n d e v , 
 	 	 	 	   s t r u c t   n e t _ d e v i c e   * o u t d e v , 
 	 	 	 	   i n t   ( * o k f n ) ( s t r u c t   s k _ b u f f   * ) ,   i n t   t h r e s h , 
 	 	 	 	   i n t   c o n d ) 
 { 
 	 r e t u r n   o k f n ( s k b ) ; 
 } 
 s t a t i c   i n l i n e   i n t   n f _ h o o k ( u _ i n t 8 _ t   p f ,   u n s i g n e d   i n t   h o o k ,   s t r u c t   s k _ b u f f   * s k b , 
 	 	 	     s t r u c t   n e t _ d e v i c e   * i n d e v ,   s t r u c t   n e t _ d e v i c e   * o u t d e v , 
 	 	 	     i n t   ( * o k f n ) ( s t r u c t   s k _ b u f f   * ) ) 
 { 
 	 r e t u r n   1 ; 
 } 
 s t r u c t   f l o w i ; 
 s t a t i c   i n l i n e   v o i d 
 n f _ n a t _ d e c o d e _ s e s s i o n ( s t r u c t   s k _ b u f f   * s k b ,   s t r u c t   f l o w i   * f l ,   u _ i n t 8 _ t   f a m i l y ) 
 { 
 } 
 # e n d i f   / * C O N F I G _ N E T F I L T E R * / 
 
 # i f   d e f i n e d ( C O N F I G _ N F _ C O N N T R A C K )   | |   d e f i n e d ( C O N F I G _ N F _ C O N N T R A C K _ M O D U L E ) 
 e x t e r n   v o i d   ( * i p _ c t _ a t t a c h ) ( s t r u c t   s k _ b u f f   * ,   s t r u c t   s k _ b u f f   * ) ; 
 e x t e r n   v o i d   n f _ c t _ a t t a c h ( s t r u c t   s k _ b u f f   * ,   s t r u c t   s k _ b u f f   * ) ; 
 e x t e r n   v o i d   ( * n f _ c t _ d e s t r o y ) ( s t r u c t   n f _ c o n n t r a c k   * ) ; 
 # e l s e 
 s t a t i c   i n l i n e   v o i d   n f _ c t _ a t t a c h ( s t r u c t   s k _ b u f f   * n e w ,   s t r u c t   s k _ b u f f   * s k b )   { } 
 # e n d i f 
 
 # e n d i f   / * _ _ K E R N E L _ _ * / 
 # e n d i f   / * _ _ L I N U X _ N E T F I L T E R _ H * / 
 