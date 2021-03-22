from easyAI.AI import Negamax
from easyAI.AI import TT
from easyAI.Player import AI_Player

def id_solve(game, ai_depths, win_score, scoring=None,
          tt=None, verbose=True):
   
    
    if not hasattr(game, 'players'): 
        game = game(players = [AI_Player(None), AI_Player(None)])
    
    for depth in ai_depths:
        ai = Negamax(depth, scoring, tt= tt)
        ai(game)
        alpha = ai.alpha
        if verbose:
             print( "d:%d, a:%d, m:%s"%(depth, alpha, str(game.ai_move)))
        if abs(alpha) >= win_score:
            break
    
    
    result = (+1 if alpha>= win_score else (
             -1 if alpha <= -win_score else 0))
    
    return result, depth, game.ai_move


def df_solve(game, win_score, maxdepth=50, tt=None, depth=0):
   
    
    
    lookup = None if (tt is None) else tt.lookup(game)
    if lookup != None:
        return lookup['value']
        
    if (depth == maxdepth):
        raise "Max recursion depth reached :("
    
    if game.is_over():
        score = game.scoring()
        value = 1 if (score>=win_score) else (-1 if -score>=win_score else 0)
        tt.store(game=game, value=value, move=None)
        return  value
    
    possible_moves = game.possible_moves()
    
    state = game
    unmake_move = hasattr(state, 'unmake_move')
    
    best_value, best_move = -1, None
    
    for move in possible_moves:
        
        if not unmake_move:
            game = state.copy() 
        
        game.make_move(move)
        game.switch_player()
        
        move_value = - df_solve(game,  win_score,  maxdepth, tt, depth+1)
        
        if unmake_move:
            game.switch_player()
            game.unmake_move(move)
        
        if move_value == 1:
            tt.store(game=state, value=1, move=move)
            return move_value
        
        if move_value == 0 and best_value==-1:
            
            best_value = 0
            best_move = move
    
    tt.store(game=state, value=best_value, move=best_move)
    
    return best_value
