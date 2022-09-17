/*
 * Copyright (c) 2022 Renwei
 *
 * This is a free software; you can redistribute it and/or modify
 * it under the terms of the MIT license. See LICENSE for details.
 */

#include "base_macro.h"
#if defined(__DAVE_BASE__)
#include "dave_base.h"
#include "dave_3rdparty.h"

void dos_exit_reset(void);
void dos_ls_reset(void);
void dos_hi_reset(void);
void dos_debug_reset(void);
void dos_echo_reset(void);
void dos_cfg_reset(void);
void dos_sync_reset(void);
void dos_log_reset(void);
void dos_test_reset(void);

// =====================================================================

void
dos_app_reset(void)
{
	dos_ls_reset();
	dos_exit_reset();
	dos_hi_reset();
	dos_debug_reset();
	dos_echo_reset();
	dos_cfg_reset();
	dos_sync_reset();
	dos_log_reset();
#if defined(GTEST_3RDPARTY)
	dos_test_reset();
#endif
}

#endif

