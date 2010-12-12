///////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2010 by Ralf Holly.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
///////////////////////////////////////////////////////////////////////////////

#include "IssueTable.h"

#include <cassert>

const int IssueTable::MAX_ISSUE_NUMBER;

size_t IssueTable::getIssueTableSize()
{
    return sizeof(ISSUE_TABLE) / sizeof(ISSUE_TABLE[0]);
}

int IssueTable::getSeverity(int number)
{
   const size_t tableSize = getIssueTableSize();

   for (size_t i = 0; i < tableSize; ++i) {
       if (ISSUE_TABLE[i].lowerBound <= number &&
           ISSUE_TABLE[i].upperBound >= number) {
           return ISSUE_TABLE[i].severity;
        }
   }
   // Error: issue not contained within issue table.
   assert(false);
   // TODO:2010-12-12:ralf:Add proper error handling.
   return -1;
}

const char* IssueTable::getIssueTableTitleByIndex(size_t i)
{
    assert(0 <= i && i <= getIssueTableSize());
    return ISSUE_TABLE[i].title;
}

int IssueTable::getIssueTableSeverityByIndex(size_t i)
{
    assert(0 <= i && i <= getIssueTableSize());
    return ISSUE_TABLE[i].severity;
}

