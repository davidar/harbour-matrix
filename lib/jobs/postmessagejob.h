/******************************************************************************
 * Copyright (C) 2015 Felix Rohrbach <kde@fxrh.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef QMATRIXCLIENT_POSTMESSAGEJOB_H
#define QMATRIXCLIENT_POSTMESSAGEJOB_H

#include "basejob.h"

namespace QMatrixClient
{
    class Room;
    class PostMessageJob: public BaseJob
    {
        public:
            PostMessageJob(ConnectionData* connection, Room* room, QString type, QString message);
            virtual ~PostMessageJob();

            //bool success();

        protected:
            QString apiPath() const override;
            QJsonObject data() const override;
            Status parseJson(const QJsonDocument& data) override;

        private:
            class Private;
            Private* d;
    };
}

#endif // QMATRIXCLIENT_POSTMESSAGEJOB_H
