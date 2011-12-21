/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * libmm -- Access modem status & information from glib applications
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 * Copyright (C) 2011 Aleksander Morgado <aleksander@gnu.org>
 */

#ifndef _MM_BEARER_H_
#define _MM_BEARER_H_

#include <ModemManager.h>
#include <mm-gdbus-bearer.h>

G_BEGIN_DECLS

/**
 * MMBearerIpConfig:
 *
 * Addressing details for assignment to the data interface.
 * This is an opaque struct.
 */
typedef struct _MMBearerIpConfig MMBearerIpConfig;

/**
 * MMBearerProperties:
 *
 * Addressing details for assignment to the data interface.
 * This is an opaque struct.
 */
typedef struct _MMBearerProperties MMBearerProperties;

typedef MmGdbusBearer     MMBearer;
#define MM_TYPE_BEARER(o) MM_GDBUS_TYPE_BEARER (o)
#define MM_BEARER(o)      MM_GDBUS_BEARER(o)
#define MM_IS_BEARER(o)   MM_GDBUS_IS_BEARER(o)

const gchar *mm_bearer_get_path      (MMBearer *self);
gchar       *mm_bearer_dup_path      (MMBearer *self);
const gchar *mm_bearer_get_interface (MMBearer *self);
gchar       *mm_bearer_dup_interface (MMBearer *self);
gboolean     mm_bearer_get_connected (MMBearer *self);
gboolean     mm_bearer_get_suspended (MMBearer *self);

void     mm_bearer_connect        (MMBearer *self,
                                   const gchar *number,
                                   GCancellable *cancellable,
                                   GAsyncReadyCallback callback,
                                   gpointer user_data);
gboolean mm_bearer_connect_finish (MMBearer *self,
                                   GAsyncResult *res,
                                   GError **error);
gboolean mm_bearer_connect_sync   (MMBearer *self,
                                   const gchar *number,
                                   GCancellable *cancellable,
                                   GError **error);

void     mm_bearer_disconnect        (MMBearer *self,
                                      GCancellable *cancellable,
                                      GAsyncReadyCallback callback,
                                      gpointer user_data);
gboolean mm_bearer_disconnect_finish (MMBearer *self,
                                      GAsyncResult *res,
                                      GError **error);
gboolean mm_bearer_disconnect_sync   (MMBearer *self,
                                      GCancellable *cancellable,
                                      GError **error);

const MMBearerProperties *mm_bearer_get_properties (MMBearer *self);
MMBearerProperties       *mm_bearer_dup_properties (MMBearer *self);

const gchar *mm_bearer_properties_get_apn           (const MMBearerProperties *properties);
gchar       *mm_bearer_properties_dup_apn           (const MMBearerProperties *properties);
const gchar *mm_bearer_properties_get_ip_type       (const MMBearerProperties *properties);
gchar       *mm_bearer_properties_dup_ip_type       (const MMBearerProperties *properties);
const gchar *mm_bearer_properties_get_user          (const MMBearerProperties *properties);
gchar       *mm_bearer_properties_dup_user          (const MMBearerProperties *properties);
const gchar *mm_bearer_properties_get_password      (const MMBearerProperties *properties);
gchar       *mm_bearer_properties_dup_password      (const MMBearerProperties *properties);
const gchar *mm_bearer_properties_get_number        (const MMBearerProperties *properties);
gchar       *mm_bearer_properties_dup_number        (const MMBearerProperties *properties);
gboolean     mm_bearer_properties_get_allow_roaming (const MMBearerProperties *properties);
void         mm_bearer_properties_free              (MMBearerProperties *properties);

const MMBearerIpConfig *mm_bearer_get_ipv4_config (MMBearer *self);
MMBearerIpConfig       *mm_bearer_dup_ipv4_config (MMBearer *self);
const MMBearerIpConfig *mm_bearer_get_ipv6_config (MMBearer *self);
MMBearerIpConfig       *mm_bearer_dup_ipv6_config (MMBearer *self);

MMBearerIpMethod   mm_bearer_ip_config_get_method  (const MMBearerIpConfig *config);
const gchar       *mm_bearer_ip_config_get_address (const MMBearerIpConfig *config);
gchar             *mm_bearer_ip_config_dup_address (const MMBearerIpConfig *config);
guint              mm_bearer_ip_config_get_prefix  (const MMBearerIpConfig *config);
const gchar      **mm_bearer_ip_config_get_dns     (const MMBearerIpConfig *config);
gchar            **mm_bearer_ip_config_dup_dns     (const MMBearerIpConfig *config);
const gchar       *mm_bearer_ip_config_get_gateway (const MMBearerIpConfig *config);
gchar             *mm_bearer_ip_config_dup_gateway (const MMBearerIpConfig *config);
void               mm_bearer_ip_config_free        (MMBearerIpConfig *config);

G_END_DECLS

#endif /* _MM_BEARER_H_ */