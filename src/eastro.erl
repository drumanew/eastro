-module(eastro).

-export([hello/1]).

-on_load(on_load/0).
on_load() ->
  PrivDir = case code:priv_dir(?MODULE) of
    {error, _} ->
      AppPath = filename:dirname(filename:dirname(code:which(?MODULE))),
      filename:join(AppPath, "priv");
    Path ->
      Path
  end,
  erlang:load_nif(filename:join(PrivDir, "eastro"), 0).

hello(_) ->
  erlang:nif_error({not_loaded, ?MODULE}).
