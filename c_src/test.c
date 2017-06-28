#include "erl_nif.h"

static int loads = 0;

static int load(ErlNifEnv* env, void** priv_data, ERL_NIF_TERM load_info)
{
	/* Initialize private data. */
	*priv_data = NULL;

	loads++;

	return 0;
}

static int upgrade(ErlNifEnv* env, void** priv_data, void** old_priv_data, ERL_NIF_TERM load_info)
{
	/* Convert the private data to the new version. */
	*priv_data = *old_priv_data;

	loads++;

	return 0;
}

static void unload(ErlNifEnv* env, void* priv_data)
{
	if (loads == 1) {
		/* Destroy the private data. */
	}

	loads--;
}

static ERL_NIF_TERM hello(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
	if (enif_is_atom(env, argv[0])) {
		return enif_make_tuple2(env,
			enif_make_atom(env, "hello"),
			argv[0]);
	}

	return enif_make_tuple2(env,
		enif_make_atom(env, "error"),
		enif_make_atom(env, "badarg"));
}

static ErlNifFunc nif_funcs[] = {
	{"hello", 1, hello}
};

ERL_NIF_INIT(eastro, nif_funcs, load, NULL, upgrade, unload)
