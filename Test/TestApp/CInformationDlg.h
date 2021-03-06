// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#pragma once

#include "CDialogBase.h"

class CInformationDlg : public CDialogBase
{
	DECLARE_DYNAMIC(CInformationDlg)

public:
	CInformationDlg(CWnd* pParent = nullptr);
	virtual ~CInformationDlg();

	void SetWindowTitle(const CString& title) { m_WindowTitle = title; }
	void SetInformationText(const CString& info_txt) { m_InfoText = info_txt; }

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnInitDialog();

private:
	CString m_WindowTitle;
	CString m_InfoText;
};
